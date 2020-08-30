/*
 *********************************************************************************************************
 *                                              EXAMPLE CODE
 *
 *                          (c) Copyright 2003-2006; Micrium, Inc.; Weston, FL
 *
 *               All rights reserved.  Protected by international copyright laws.
 *               Knowledge of the source code may NOT be used to develop a similar product.
 *               Please help us continue to provide the Embedded community with the finest
 *               software available.  Your honesty is greatly appreciated.
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *
 *                                            EXAMPLE CODE
 *
 *                                     ST Microelectronics STM32
 *                                              with the
 *                                   STM3210B-EVAL Evaluation Board
 *
 * Filename      : app.c
 * Version       : V1.10
 * Programmer(s) : BAN
 *********************************************************************************************************
 */


/*
 *********************************************************************************************************
 *                                             INCLUDE FILES
 *********************************************************************************************************
 */

#include <includes.h>



/*
 *********************************************************************************************************
 *                                            LOCAL DEFINES
 *********************************************************************************************************
 */
/*
 *********************************************************************************************************
 *                                            USER DEFINED STRUCTURE
 *********************************************************************************************************
 */
#define SYSTEM_CORE_CLOCK 72000000  //System Base Clock is 72MHz

/*
 *********************************************************************************************************
 *                                              datas
 *
 * Description :  This is Structure of data both of input from sensor's
 *
 * obstacle Data: for obstacle sensor's input value
 * sound Data: for sound sensor's input value
 *********************************************************************************************************
 */
typedef struct datas{
    CPU_INT16U obstacleData;
    CPU_INT16U soundData;
} DataSet;
/*
 *********************************************************************************************************
 *                                              selections
 *
 * Description :  This is Structure of output data both of deciding execution of output
 *
 * obstacle Output : for obstacle sensor's result output
 * sound Output : for sound sensor's result output
 *********************************************************************************************************
 */
typedef struct selections{
    CPU_INT16U obstacleOutput;
    CPU_INT16U soundOutput;
} Selection;

/*
 *********************************************************************************************************
 *                                       LOCAL GLOBAL VARIABLES
 *********************************************************************************************************
 */
//FOR STACK
static OS_STK App_TaskStartStk[APP_TASK_START_STK_SIZE];
static OS_STK App_Process_TaskStartStk[APP_PRO_TASK_START_STK_SIZE];
static OS_STK App_Output_TaskStartStk[APP_OUT_TASK_START_STK_SIZE];
static OS_STK App_TaskUserIFStk[APP_TASK_USER_IF_STK_SIZE];
static OS_STK App_TaskKbdStk[APP_TASK_KBD_STK_SIZE];

//FOR MAILBOX
static OS_EVENT      *App_UserIFMbox;
static OS_EVENT      *App_INP_PRO_Mbox;
static OS_EVENT      *App_PRO_OUT_Mbox;

#if ((APP_OS_PROBE_EN == DEF_ENABLED) && \
	(APP_PROBE_COM_EN == DEF_ENABLED) && \
	(PROBE_COM_STAT_EN == DEF_ENABLED))
static CPU_FP32 App_ProbeComRxPktSpd;
static CPU_FP32 App_ProbeComTxPktSpd;
static CPU_FP32 App_ProbeComTxSymSpd;
static CPU_FP32 App_ProbeComTxSymByteSpd;

static CPU_INT32U App_ProbeComRxPktLast;
static CPU_INT32U App_ProbeComTxPktLast;
static CPU_INT32U App_ProbeComTxSymLast;
static CPU_INT32U App_ProbeComTxSymByteLast;

static CPU_INT32U App_ProbeComCtrLast;
#endif

#if (APP_OS_PROBE_EN == DEF_ENABLED)
static CPU_INT32U App_ProbeCounts;
static CPU_BOOLEAN App_ProbeB1;

#endif


/*
 *********************************************************************************************************
 *                                      LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************
 */

static void  App_TaskCreate(void);
static void  App_EventCreate(void);

static void  App_TaskStart(void        *p_arg);
static void  App_Process_TaskStart(void        *p_arg);
static void  App_Output_TaskStart(void        *p_arg);
static void  App_TaskUserIF(void        *p_arg);
static void  App_TaskKbd(void        *p_arg);

static void  App_DispScr_SignOn(void);
static void  App_DispScr_TaskNames(void);

static void TIMER_Configure(void);
static void Init_For_Obst_Sensor(void);

#if ((APP_PROBE_COM_EN == DEF_ENABLED) || \
	(APP_OS_PROBE_EN == DEF_ENABLED))
static void  App_InitProbe(void);
#endif

#if (APP_OS_PROBE_EN == DEF_ENABLED)
static void  App_ProbeCallback(void);
#endif


/*
 *********************************************************************************************************
 *                                                main()
 *
 * Description : This is the standard entry point for C code.  It is assumed that your code will call
 *               main() once you have performed all necessary initialization.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *********************************************************************************************************
 */
int  main(void)
{
	CPU_INT08U os_err;

	/* Disable all ints until we are ready to accept them.  */
	BSP_IntDisAll();


	/* Initialize "uC/OS-II, The Real-Time Kernel".         */
	/* IDLE Task와 Statistics Task 생성                      */
	OSInit();

	/* Create the start task.                               */
	/* OSTaskCreatExt()                                     */
	/* OSTaskCreate()와 다르게 Stack을 검사할수 있는 기능을 가짐 */
        //1st. input task
	os_err = OSTaskCreateExt((void (*)(void *))App_TaskStart, // Task가 수행할 함수 
				 (void* )0,                     // Task로 넘겨줄 인자
				 (OS_STK* )&App_TaskStartStk[APP_TASK_START_STK_SIZE - 1],     // Task가 할당될 Stack의 Top을 가리키는 주소
				 (INT8U           )APP_TASK_START_PRIO,// Task의 우선 순위(3으로 최우선순위 -> 이유 :  제일 처음으로 실행)
				 (INT16U          )APP_TASK_START_PRIO,// Task를 지칭하는 유일한 식별자, Task 갯수의 극복을 위해서 사용할 예정, 현재는 우선 순위와 같게끔 설정
				 (OS_STK* )&App_TaskStartStk[0],     // Task가 할당될 Stack의 마지막을 가리키는 주소, Stack 검사용으로 사용
				 (INT32U          )APP_TASK_START_STK_SIZE,// Task Stack의 크기를 의미
				 (void* )0,       // Task Control Block 활용시 사용
				 (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));// Task 생성 옵션 - 초기화 시 Stack을 0으로 채울 것인지, 부동 소수점 연산 장치 사용할 것인지 등 설정
        //Add task2
        //2nd. processing task
        os_err = OSTaskCreateExt((void (*)(void *))App_Process_TaskStart, // Task가 수행할 함수
				 (void* )0,                     // Task로 넘겨줄 인자
				 (OS_STK* )&App_Process_TaskStartStk[APP_TASK_START_STK_SIZE - 1],     // Task가 할당될 Stack의 Top을 가리키는 주소
				 (INT8U           )APP_PRO_TASK_START_PRIO,// Task의 우선 순위(4로 차선순위 -> 이유 : 두번째로 실행)
				 (INT16U          )APP_PRO_TASK_START_PRIO,// Task를 지칭하는 유일한 식별자, Task 갯수의 극복을 위해서 사용할 예정, 현재는 우선 순위와 같게끔 설정
				 (OS_STK* )&App_Process_TaskStartStk[0],     // Task가 할당될 Stack의 마지막을 가리키는 주소, Stack 검사용으로 사용
				 (INT32U          )APP_PRO_TASK_START_STK_SIZE,// Task Stack의 크기를 의미
				 (void* )0,       // Task Control Block 활용시 사용
				 (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));// Task 생성 옵션 - 초기화 시 Stack을 0으로 채울 것인지, 부동 소수점 연산 장치 사용할 것인지 등 설정

        //Add task3
        ///3rd. output task
        os_err = OSTaskCreateExt((void (*)(void *))App_Output_TaskStart, // Task가 수행할 함수
				 (void* )0,                     // Task로 넘겨줄 인자
				 (OS_STK* )&App_Output_TaskStartStk[APP_OUT_TASK_START_STK_SIZE - 1],     // Task가 할당될 Stack의 Top을 가리키는 주소
				 (INT8U           )APP_OUT_TASK_START_PRIO,// Task의 우선 순위(5로 Task중에서는 최하순위 -> 이유 : 3번째로 실행)
				 (INT16U          )APP_OUT_TASK_START_PRIO,// Task를 지칭하는 유일한 식별자, Task 갯수의 극복을 위해서 사용할 예정, 현재는 우선 순위와 같게끔 설정
				 (OS_STK* )&App_Output_TaskStartStk[0],     // Task가 할당될 Stack의 마지막을 가리키는 주소, Stack 검사용으로 사용
				 (INT32U          )APP_OUT_TASK_START_STK_SIZE,// Task Stack의 크기를 의미
				 (void* )0,       // Task Control Block 활용시 사용
				 (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));// Task 생성 옵션 - 초기화 시 Stack을 0으로 채울 것인지, 부동 소수점 연산 장치 사용할 것인지 등 설정
        

#if (OS_TASK_NAME_SIZE >= 11)
	OSTaskNameSet(APP_TASK_START_PRIO, (CPU_INT08U*)"Start Task", &os_err);
#endif

	OSStart();                                              /* Start multitasking (i.e. give control to uC/OS-II).  */

	return(0);
}


/*
 *********************************************************************************************************
 *                                          App_TaskStart()
 *
 * Description : The startup task.  The uC/OS-II ticker should only be initialize once multitasking starts.
 *
 * Argument(s) : p_arg       Argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : This is a task.
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */
// INPUT을 위한 Task
static void  App_TaskStart(void *p_arg)
{
	DataSet input;
	(void)p_arg;

	BSP_Init();                                             /* Initialize BSP functions.                            */
	OS_CPU_SysTickInit();                                   /* Initialize the SysTick.                              */
        
#if (OS_TASK_STAT_EN > 0)
	OSStatInit();                                           /* Determine CPU capacity.                              */
#endif

#if ((APP_PROBE_COM_EN == DEF_ENABLED) || \
	(APP_OS_PROBE_EN == DEF_ENABLED))
	App_InitProbe();
#endif
        Init_For_Obst_Sensor();
	/* Create application events.                           */
	/* Task간 통신을 위한 MailBox 생성                        */
	App_EventCreate();

	/* Create application tasks.                            */
	/* LCD 갱신 Task, 키보드 입력 Task 생성                    */
	App_TaskCreate();
        
	/* Task body, always written as an infinite loop.       */
	while (DEF_TRUE) {
                //
                input.obstacleData = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2);
                input.soundData = ADC_GetConversionValue(ADC1);
                OSMboxPost(App_INP_PRO_Mbox, &input);
                OSTimeDlyHMSM(0, 0, 0,20);
	}
}
/*
 *********************************************************************************************************
 *                                          App_Process_TaskStart()
 *
 * Description : The processing Task.  The uC/OS-II ticker should only be initialize once multitasking starts.
 *
 * Argument(s) : p_arg       
 *
 * Return(s)   : none.
 *
 * Caller(s)   : This is a task.
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */
// 정보 처리를 위한 Task
static void  App_Process_TaskStart(void *p_arg)
{
        DataSet *input;
        Selection output;
        CPU_INT08U err;
	(void)p_arg;

	BSP_Init();                                             /* Initialize BSP functions.                            */
	OS_CPU_SysTickInit();                                   /* Initialize the SysTick.                              */

#if (OS_TASK_STAT_EN > 0)
	OSStatInit();                                           /* Determine CPU capacity.                              */
#endif

#if ((APP_PROBE_COM_EN == DEF_ENABLED) || \
	(APP_OS_PROBE_EN == DEF_ENABLED))
	App_InitProbe();
#endif
	/* Task body, always written as an infinite loop.       */
             
	while (DEF_TRUE) {
                  input = (DataSet*)OSMboxPend(App_INP_PRO_Mbox, OS_TICKS_PER_SEC / 10, &err);
                  if(!(input->obstacleData)){
                      output.obstacleOutput = DEF_TRUE;
                  }
                  else{
                     output.obstacleOutput = DEF_FALSE;
                  }
                  if((input->soundData>200)&&(input->soundData<1000)){
                      output.soundOutput = DEF_TRUE;
                  }
                  else{
                      output.soundOutput = DEF_FALSE;
                  }
                  printf("%d\n%d\n%d,%d\n", input->obstacleData, input->soundData, output.obstacleOutput, output.soundOutput);
                  OSMboxPost(App_PRO_OUT_Mbox, &output);
                  OSTimeDlyHMSM(0, 0, 0,20);
	}
}
/*
 *********************************************************************************************************
 *                                          App_Output_TaskStart()
 *
 * Description : The output task.  The uC/OS-II ticker should only be initialize once multitasking starts.
 *
 * Argument(s) : p_arg       
 *
 * Return(s)   : none.
 *
 * Caller(s)   : This is a task.
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */
// OUTPUT을 위한 Task
static void  App_Output_TaskStart(void *p_arg)
{
        CPU_INT08U err;
        Selection* selection;
	BSP_Init();                                             /* Initialize BSP functions.                            */
	OS_CPU_SysTickInit();                                   /* Initialize the SysTick.                              */
        TIMER_Configure();

#if (OS_TASK_STAT_EN > 0)
	OSStatInit();                                           /* Determine CPU capacity.                              */
#endif

#if ((APP_PROBE_COM_EN == DEF_ENABLED) || \
	(APP_OS_PROBE_EN == DEF_ENABLED))
	App_InitProbe();
#endif
         
	/* Task body, always written as an infinite loop.       */
	while (DEF_TRUE) {
          //to do implement
              selection = (Selection*)OSMboxPend(App_PRO_OUT_Mbox, OS_TICKS_PER_SEC / 10, &err);
              if(selection->obstacleOutput){
                  TIM_Cmd(TIM4, ENABLE); 
              }
              else{
                TIM_Cmd(TIM4, DISABLE);                 
              }
              if(selection->soundOutput){
                  BSP_LED_On(0);
              }
              else{
                  BSP_LED_Off(0); // LED ON
              }
              OSTimeDlyHMSM(0, 0, 0, 20);
	}
}
/*
 *********************************************************************************************************
 *                                              TIMER_Configure
 *
 * Description :  This is Setting for Using Speaker with TIM4, GPIOB_Pin8
 *                      Calculate from clock tree, match frequency and PWM of speaker.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 * 
 * Caller(s)   : App_Output_TaskStart().
 * 
 *********************************************************************************************************
 */
static void TIMER_Configure(void){ //FROM Khan's Embedded System Experiment's Term Project
      TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
      TIM_OCInitTypeDef TIM_OCInitStructure;
      GPIO_InitTypeDef GPIO_InitStructure; 
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE );   
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
      GPIO_Init(GPIOB, &GPIO_InitStructure); 
      TIM_TimeBaseStructure.TIM_Prescaler = (INT16U) (SYSTEM_CORE_CLOCK / 1000000) - 1; 
      TIM_TimeBaseStructure.TIM_Period = 20000-1;             // set to 50Hz PWM Clock     
      TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
      TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down; 
      TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);      /* PWM1 Mode configuration: Channel3 */    
      TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  
      TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
      TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
      TIM_OCInitStructure.TIM_Pulse = 2000;                  // 50 % duty cycle value  
      TIM_OC3Init(TIM4, &TIM_OCInitStructure);  
      TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Disable);  
      TIM_ARRPreloadConfig(TIM4, ENABLE);  
}
/*
 *********************************************************************************************************
 *                                              init_For_Obst_Sensor
 *
 * Description :  This is  RCC & GPIO Setting for Obstacle Sensor with GPIOD_Pin2
 *
 * Argument(s) : none.
 *
 * Return(s)   : none. 
 *
 * Caller(s)   : Tpp_TaskStart().
 *********************************************************************************************************
 */

void Init_For_Obst_Sensor(void){
      GPIO_InitTypeDef  gpio_init;
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
      gpio_init.GPIO_Pin  = GPIO_Pin_2;
      gpio_init.GPIO_Mode = GPIO_Mode_IPD;
      GPIO_Init(GPIOD, &gpio_init);
  
}
/*
 *********************************************************************************************************
 *                                             App_EventCreate()
 *
 * Description : Create the application events.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : App_TaskStart().
 *
 * Note(s)     : This Function Create Mailbox.
 *********************************************************************************************************
 */

static void  App_EventCreate(void)
{
#if (OS_EVENT_NAME_SIZE > 12)
	CPU_INT08U os_err;
#endif

	/* Create MBOX for communication between Kbd and UserIF.*/
	/* Mail Box 생성                                         */
	/* 포인터 크기의 변수를 Task나 Interrupt Service Routine   */
	/* 에서 다른 Task 전달할 때 사용함                         */
	App_UserIFMbox = OSMboxCreate((void*)0);
        App_INP_PRO_Mbox = OSMboxCreate((void*)0);
        App_PRO_OUT_Mbox = OSMboxCreate((void*)0);
#if (OS_EVENT_NAME_SIZE > 12)
	OSEventNameSet(App_UserIFMbox, "User IF Mbox", &os_err);
        OSEventNameSet(App_INP_PRO_Mbox, "Bt ItoP Mbox", &os_err);
        OSEventNameSet(App_PRO_OUT_Mbox, "Bt PtoO Mbox", &os_err);
#endif
}


/*
 *********************************************************************************************************
 *                                            App_TaskCreate()
 *
 * Description : Create the application tasks.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : App_TaskStart().
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */

static void  App_TaskCreate(void)
{
	CPU_INT08U os_err;

	// LCD를 갱신시키는 Task 생성
	os_err = OSTaskCreateExt((void (*)(void *))App_TaskUserIF,
				 (void* )0,
				 (OS_STK* )&App_TaskUserIFStk[APP_TASK_USER_IF_STK_SIZE - 1],
				 (INT8U           )APP_TASK_USER_IF_PRIO,
				 (INT16U          )APP_TASK_USER_IF_PRIO,
				 (OS_STK* )&App_TaskUserIFStk[0],
				 (INT32U          )APP_TASK_USER_IF_STK_SIZE,
				 (void* )0,
				 (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));

#if (OS_TASK_NAME_SIZE >= 9)
	OSTaskNameSet(APP_TASK_USER_IF_PRIO, "User I/F", &os_err);
#endif
	// Keyboard 입력을 받는 Task 생성
	os_err = OSTaskCreateExt((void (*)(void *))App_TaskKbd,
				 (void* )0,
				 (OS_STK* )&App_TaskKbdStk[APP_TASK_KBD_STK_SIZE - 1],
				 (INT8U           )APP_TASK_KBD_PRIO,
				 (INT16U          )APP_TASK_KBD_PRIO,
				 (OS_STK* )&App_TaskKbdStk[0],
				 (INT32U          )APP_TASK_KBD_STK_SIZE,
				 (void* )0,
				 (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));
#if (OS_TASK_NAME_SIZE >= 9)
	OSTaskNameSet(APP_TASK_KBD_PRIO, "Keyboard", &os_err);
#endif
}


/*
 *********************************************************************************************************
 *                                            App_TaskKbd()
 *
 * Description : Monitor the state of the push buttons and passes messages to AppTaskUserIF()
 *
 * Argument(s) : p_arg       Argument passed to 'App_TaskKbd()' by 'OSTaskCreate()'.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : This is a task.
 *
 * Note(s)     : not use(just mailbox by reference)
 *********************************************************************************************************
 */

// Keyboard 입력을 받는 Task
static void  App_TaskKbd(void *p_arg)
{
	CPU_BOOLEAN b1_prev;
	CPU_BOOLEAN b1;
	CPU_INT08U key;


	(void)p_arg;

	b1_prev = DEF_FALSE;
	key = 1;

	while (DEF_TRUE) {
		b1 = BSP_PB_GetStatus(BSP_PB_ID_KEY);

		if ((b1 == DEF_TRUE) && (b1_prev == DEF_FALSE)) {
			if (key == 2) {
				key = 1;
			} else {
				key++;
			}
			// MailBox에 Task에서 입력받은 값 Key를 전달
			OSMboxPost(App_UserIFMbox, (void*)key);
		}

		b1_prev = b1;

		OSTimeDlyHMSM(0, 0, 0, 20);
	}
}


/*
 *********************************************************************************************************
 *                                            App_TaskUserIF()
 *
 * Description : Updates LCD.
 *
 * Argument(s) : p_arg       Argument passed to 'App_TaskUserIF()' by 'OSTaskCreate()'.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : This is a task.
 *
 * Note(s)     : not use(just mailbox by reference)
 *********************************************************************************************************
 */

// LCD 갱신을 위한 Task
static void  App_TaskUserIF(void *p_arg)
{
	CPU_INT08U  *msg;
	CPU_INT08U err;
	CPU_INT32U nstate;
	CPU_INT32U pstate;


	(void)p_arg;


	App_DispScr_SignOn();
	OSTimeDlyHMSM(0, 0, 1, 0);
	nstate = 1;
	pstate = 1;


	while (DEF_TRUE) {
		// 다른 Task에서 Mailbox에 전달한 저장된 값을 받음
		msg = (CPU_INT08U*)(OSMboxPend(App_UserIFMbox, OS_TICKS_PER_SEC / 10, &err));
		if (err == OS_NO_ERR) {
			nstate = (CPU_INT32U)msg;
		}

		if (nstate != pstate) {
			pstate = nstate;
		}

		switch (nstate) {
		case 2:
			App_DispScr_TaskNames();
			break;

		case 1:
		default:
			App_DispScr_SignOn();
			break;
		}
	}
}


/*
 *********************************************************************************************************
 *                                          App_DispScr_SignOn()
 *
 * Description : Display uC/OS-II system information on the LCD.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : App_TaskUserIF().
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */

static void  App_DispScr_SignOn(void)
{
}



/*
 *********************************************************************************************************
 *                                          App_DispScr_SignOn()
 *
 * Description : Display uC/OS-II system information on the LCD.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : App_TaskUserIF().
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */

static void  App_DispScr_TaskNames(void)
{
}


/*
 *********************************************************************************************************
 *                                             App_InitProbe()
 *
 * Description : Initialize uC/Probe target code.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : App_TaskStart().
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */

#if ((APP_PROBE_COM_EN == DEF_ENABLED) || \
	(APP_OS_PROBE_EN == DEF_ENABLED))
static void  App_InitProbe(void)
{
#if (APP_OS_PROBE_EN == DEF_ENABLED)
	(void)App_ProbeCounts;
	(void)App_ProbeB1;


#if ((APP_PROBE_COM_EN == DEF_ENABLED) && \
	(PROBE_COM_STAT_EN == DEF_ENABLED))
	(void)App_ProbeComRxPktSpd;
	(void)App_ProbeComTxPktSpd;
	(void)App_ProbeComTxSymSpd;
	(void)App_ProbeComTxSymByteSpd;
#endif

	OSProbe_Init();
	OSProbe_SetCallback(App_ProbeCallback);
	OSProbe_SetDelay(250);
#endif

#if (APP_PROBE_COM_EN == DEF_ENABLED)
	ProbeCom_Init();                                        /* Initialize the uC/Probe communications module.       */
#endif
}
#endif


/*
 *********************************************************************************************************
 *                                         AppProbeCallback()
 *
 * Description : uC/Probe OS plugin callback.
 *
 * Argument(s) : none.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : uC/Probe OS plugin task.
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */

#if (APP_OS_PROBE_EN == DEF_ENABLED)
static void  App_ProbeCallback(void)
{
#if ((APP_PROBE_COM_EN == DEF_ENABLED) && \
	(PROBE_COM_STAT_EN == DEF_ENABLED))
	CPU_INT32U ctr_curr;
	CPU_INT32U rxpkt_curr;
	CPU_INT32U txpkt_curr;
	CPU_INT32U sym_curr;
	CPU_INT32U symbyte_curr;
#endif



	App_ProbeCounts++;

	App_ProbeB1 = BSP_PB_GetStatus(1);




#if ((APP_PROBE_COM_EN == DEF_ENABLED) && \
	(PROBE_COM_STAT_EN == DEF_ENABLED))
	ctr_curr = OSTime;
	rxpkt_curr = ProbeCom_RxPktCtr;
	txpkt_curr = ProbeCom_TxPktCtr;
	sym_curr = ProbeCom_TxSymCtr;
	symbyte_curr = ProbeCom_TxSymByteCtr;

	if ((ctr_curr - App_ProbeComCtrLast) >= OS_TICKS_PER_SEC) {
		App_ProbeComRxPktSpd = ((CPU_FP32)(rxpkt_curr - App_ProbeComRxPktLast) / (ctr_curr - App_ProbeComCtrLast)) * OS_TICKS_PER_SEC;
		App_ProbeComTxPktSpd = ((CPU_FP32)(txpkt_curr - App_ProbeComTxPktLast) / (ctr_curr - App_ProbeComCtrLast)) * OS_TICKS_PER_SEC;
		App_ProbeComTxSymSpd = ((CPU_FP32)(sym_curr - App_ProbeComTxSymLast) / (ctr_curr - App_ProbeComCtrLast)) * OS_TICKS_PER_SEC;
		App_ProbeComTxSymByteSpd = ((CPU_FP32)(symbyte_curr - App_ProbeComTxSymByteLast) / (ctr_curr - App_ProbeComCtrLast)) * OS_TICKS_PER_SEC;

		App_ProbeComCtrLast = ctr_curr;
		App_ProbeComRxPktLast = rxpkt_curr;
		App_ProbeComTxPktLast = txpkt_curr;
		App_ProbeComTxSymLast = sym_curr;
		App_ProbeComTxSymByteLast = symbyte_curr;
	}
#endif
}
#endif


/*
 *********************************************************************************************************
 *                                      App_FormatDec()
 *
 * Description : Convert a decimal value to ASCII (without leading zeros).
 *
 * Argument(s) : pstr            Pointer to the destination ASCII string.
 *
 *               value           Value to convert (assumes an unsigned value).
 *
 *               digits          The desired number of digits.
 *
 * Return(s)   : none.
 *
 * Caller(s)   : various.
 *
 * Note(s)     : none.
 *********************************************************************************************************
 */


/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                          uC/OS-II APP HOOKS
 *********************************************************************************************************
 *********************************************************************************************************
 */

#if (OS_APP_HOOKS_EN > 0)
/*
 *********************************************************************************************************
 *                                      TASK CREATION HOOK (APPLICATION)
 *
 * Description : This function is cal when a task is created.
 *
 * Argument(s) : ptcb   is a pointer to the task control block of the task being created.
 *
 * Note(s)     : (1) Interrupts are disabled during this call.
 *********************************************************************************************************
 */

void  App_TaskCreateHook(OS_TCB *ptcb)
{
#if ((APP_OS_PROBE_EN == DEF_ENABLED) && \
	(OS_PROBE_HOOKS_EN == DEF_ENABLED))
	OSProbe_TaskCreateHook(ptcb);
#endif
}

/*
 *********************************************************************************************************
 *                                    TASK DELETION HOOK (APPLICATION)
 *
 * Description : This function is called when a task is deleted.
 *
 * Argument(s) : ptcb   is a pointer to the task control block of the task being deleted.
 *
 * Note(s)     : (1) Interrupts are disabled during this call.
 *********************************************************************************************************
 */

void  App_TaskDelHook(OS_TCB *ptcb)
{
	(void)ptcb;
}

/*
 *********************************************************************************************************
 *                                      IDLE TASK HOOK (APPLICATION)
 *
 * Description : This function is called by OSTaskIdleHook(), which is called by the idle task.  This hook
 *               has been added to allow you to do such things as STOP the CPU to conserve power.
 *
 * Argument(s) : none.
 *
 * Note(s)     : (1) Interrupts are enabled during this call.
 *********************************************************************************************************
 */

#if OS_VERSION >= 251
void  App_TaskIdleHook(void)
{
}
#endif

/*
 *********************************************************************************************************
 *                                        STATISTIC TASK HOOK (APPLICATION)
 *
 * Description : This function is called by OSTaskStatHook(), which is called every second by uC/OS-II's
 *               statistics task.  This allows your application to add functionality to the statistics task.
 *
 * Argument(s) : none.
 *********************************************************************************************************
 */

void  App_TaskStatHook(void)
{
}

/*
 *********************************************************************************************************
 *                                        TASK SWITCH HOOK (APPLICATION)
 *
 * Description : This function is called when a task switch is performed.  This allows you to perform other
 *               operations during a context switch.
 *
 * Argument(s) : none.
 *
 * Note(s)     : (1) Interrupts are disabled during this call.
 *
 *               (2) It is assumed that the global pointer 'OSTCBHighRdy' points to the TCB of the task that
 *                   will be 'switched in' (i.e. the highest priority task) and, 'OSTCBCur' points to the
 *                  task being switched out (i.e. the preempted task).
 *********************************************************************************************************
 */

#if OS_TASK_SW_HOOK_EN > 0
void  App_TaskSwHook(void)
{
#if ((APP_OS_PROBE_EN == DEF_ENABLED) && \
	(OS_PROBE_HOOKS_EN == DEF_ENABLED))
	OSProbe_TaskSwHook();
#endif
}
#endif

/*
 *********************************************************************************************************
 *                                     OS_TCBInit() HOOK (APPLICATION)
 *
 * Description : This function is called by OSTCBInitHook(), which is called by OS_TCBInit() after setting
 *               up most of the TCB.
 *
 * Argument(s) : ptcb    is a pointer to the TCB of the task being created.
 *
 * Note(s)     : (1) Interrupts may or may not be ENABLED during this call.
 *********************************************************************************************************
 */

#if OS_VERSION >= 204
void  App_TCBInitHook(OS_TCB *ptcb)
{
	(void)ptcb;
}
#endif

/*
 *********************************************************************************************************
 *                                        TICK HOOK (APPLICATION)
 *
 * Description : This function is called every tick.
 *
 * Argument(s) : none.
 *
 * Note(s)     : (1) Interrupts may or may not be ENABLED during this call.
 *********************************************************************************************************
 */

#if OS_TIME_TICK_HOOK_EN > 0
void  App_TimeTickHook(void)
{
#if ((APP_OS_PROBE_EN == DEF_ENABLED) && \
	(OS_PROBE_HOOKS_EN == DEF_ENABLED))
	OSProbe_TickHook();
#endif
}
#endif
#endif
