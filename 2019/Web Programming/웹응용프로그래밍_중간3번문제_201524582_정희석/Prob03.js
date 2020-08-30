// JavaScript source code
//웹응용프로그래밍 059분반
//학번: 201524582
//이름: 정희석
//중간고사 3번 문제 풀기 JavaScript파일

function Create() { //문제 생성 양식 화면에 띄움//
    document.getElementById("DisplayProb").innerHTML = "";
    document.getElementById("Create").setAttribute("style", "display:block");
}
//1번 기능//
function Store() { //Create -> 문제 저장 버튼 누르면 발생//
    var pNum = document.getElementById("ProbNum").value;
    var pText = document.getElementById("ProbText").value;
    var pSel1 = document.getElementById("ProbSel1").value;
    var pSel2 = document.getElementById("ProbSel2").value;
    var pSel3 = document.getElementById("ProbSel3").value;
    var pSel4 = document.getElementById("ProbSel4").value;
    var pSel5 = document.getElementById("ProbSel5").value;
    var pAns = document.getElementById("ProbAns").value;
    var pSimp = document.getElementById("ProbSimp").value;
    if (pNum != '' && pText != '' && pSel1 != '' &&
        pSel2 != '' && pSel3 != '' && pSel4 != '' &&
        pSel5 != '' && pAns != '' && pSimp) {
        var prob = {
            'probNum': pNum, 'probExpl': pText, 'probSel1': pSel1, 'probSel2': pSel2,
            'probSel3': pSel3, 'probSel4': pSel4, 'probSel5': pSel5, 'probAnsw': pAns, 'probSimpExpl': pSimp
        };
        localStorage.setItem('Problem' + pNum, JSON.stringify(prob));
        alert("문제가 저장되었읍니다.");
        textReset();//입력 text box 초기화//
        makeProbList(pNum);//문제 리스트로 출력하기위해 실행//
    }
    else {//빈칸있는 경우 알림//
        if (pNum == '') alert("문제 번호를 입력해 주세요.");
        else if (pText == '') alert("문제 내용을 입력해 주세요.");
        else if (pSel1 == '') alert("1번 문항을 입력해 주세요.");
        else if (pSel2 == '') alert("2번 문항을 입력해 주세요.");
        else if (pSel3 == '') alert("3번 문항을 입력해 주세요.");
        else if (pSel4 == '') alert("4번 문항을 입력해 주세요.");
        else if (pSel5 == '') alert("5번 문항을 입력해 주세요.");
        else if (pAns == '') alert("정답 번호를 입력해 주세요.");
        else if (pSimp == '') alert("문제의 간단한 설명을 입력해 주세요.");
    }
}
//1번 기능//
function textReset() {//입력 text 초기화//
    document.getElementById("ProbNum").value = '';
    document.getElementById("ProbText").value = '';
    document.getElementById("ProbSel1").value = '';
    document.getElementById("ProbSel2").value = '';
    document.getElementById("ProbSel3").value = '';
    document.getElementById("ProbSel4").value = '';
    document.getElementById("ProbSel5").value = '';
    document.getElementById("ProbAns").value = '';
    document.getElementById("ProbSimp").value = '';
}
//1번 기능//
function makeProbList(number) {//입력받은 문제를 번호와 간단한 설명만 출력하도록 함//
    var field = document.getElementById("DisplayList");
    var pNumber = number;
    var prob = localStorage.getItem('Problem' + pNumber);
    var pSimpScri = JSON.parse(prob).probSimpExpl;
    field.innerHTML += "<p id=\"Prob" + pNumber + "\"> 문제 " +
        pNumber + "번 <br>" + pSimpScri + "<br>" +
        "<button onclick=\"Modify(" + pNumber + ")\"> 문제 수정 </button>"+
        "<button onclick=\"Remove(" + pNumber + ")\"> 문제 삭제 </button>" +
        "<button onclick=\"DisplayEachProb(" + pNumber + ")\"> 문제 풀기 </button> </p > " ;
}
//===================================================================================//
//1번 기능//
function Display() {//local storage에 저장된 모든 문제를 출력//
    textReset();//입력 text box 초기화//
    document.getElementById("Create").setAttribute("style", "display:none");
    var len = localStorage.length;
    if (len == 0) return;
    var field = document.getElementById("DisplayProb");
    if (field.innerHTML!="") field.innerHTML="";
    for (var index = 0; index < len; index++) {//전체문제//
        var probKey = localStorage.key(index);
        var prob = localStorage.getItem(probKey);
        makeProblem(field, prob);//문제를 출력하기위해 실행//
    }
}
//2번 기능//
function DisplayEachProb(number) {//문제 List에서 선택한 문제만을 출력//
    textReset();
    document.getElementById("Create").setAttribute("style", "display:none");
    var field = document.getElementById("DisplayProb");
    var prob = localStorage.getItem("Problem" + number);
    var forCheck = document.getElementById("pN" + number);
    if (forCheck!= null) return;
    makeProblem(field, prob);//문제를 출력하기위해 실행//
}
//1번, 2번 기능//
function makeProblem(field, probJSON) {//LocalStorage에 있는 문제를 출력함//
    var pNum = JSON.parse(probJSON).probNum;
    var pText = JSON.parse(probJSON).probExpl;
    var pSel1 = JSON.parse(probJSON).probSel1;
    var pSel2 = JSON.parse(probJSON).probSel2;
    var pSel3 = JSON.parse(probJSON).probSel3;
    var pSel4 = JSON.parse(probJSON).probSel4;
    var pSel5 = JSON.parse(probJSON).probSel5;
    
    var problem = "<p id=\"pN"+ pNum + "\"> Problem #" + pNum + ")<br>" + "문제 설명 : " + pText + " <br>"+
        "선택지 1 : " + pSel1 + " <br>" +"선택지 2 : " + pSel2 + " <br>" +
        "선택지 3 : " + pSel3 + " <br>" +"선택지 4 : " + pSel4 + " <br>" +
        "선택지 5 : " + pSel5 + " <br>" + "답 : <input id=\"Answ" + pNum + "\"type=\"number\" min=\"1\" max=\"5\" required>" +
        "<br>"+"<button onClick=\"Submit(" + pNum + ")\">정답 제출</button> </p>";
    field.innerHTML += problem;
}
//========================================================================//
//2번 기능//
function Submit(number) {//문제 풀 때 정/오답 여부 확인//
    var pAns = JSON.parse(localStorage.getItem('Problem' + number)).probAnsw;
    var inp = document.getElementById("Answ" + number).value;
    if (inp == "") {
        alert("답을 입력해주세요.");
        return;
    }
    if (pAns != inp) alert("문제" + number + " 틀렸읍니다! 정답은 " + pAns + "였읍니다.");
    else alert("문제"+ number + " 정답입니다!");
}
//========================================================================//
//3번 기능//
function Modify(number) {//문제를 수정할 때//
    var createField = document.getElementById("Create");
    var displayField = document.getElementById("DisplayProb");
    if (displayField.innerHTML != "" || createField.style.display == "none") {
        displayField.innerHTML = ""; //1. 문제가 출력중인 상태일 때 2.시작 초기화면일 때
        createField.style.display = 'block';//문제 생성 화면 출력
    }
    var prob = localStorage.getItem('Problem' + number);
    document.getElementById("ProbNum").value = JSON.parse(prob).probNum;
    document.getElementById("ProbText").value = JSON.parse(prob).probExpl;
    document.getElementById("ProbSel1").value = JSON.parse(prob).probSel1;
    document.getElementById("ProbSel2").value = JSON.parse(prob).probSel2;
    document.getElementById("ProbSel3").value = JSON.parse(prob).probSel3;
    document.getElementById("ProbSel4").value = JSON.parse(prob).probSel4;
    document.getElementById("ProbSel5").value = JSON.parse(prob).probSel5;
    document.getElementById("ProbAns").value = JSON.parse(prob).probAnsw;
    document.getElementById("ProbSimp").value = JSON.parse(prob).probSimpExpl;
    Remove(number);//Local Stoarge에 있는 수정 대상인 문제를 삭제.//
}
//3번 기능//
function Remove(number) {//Local Storage에 있는 문제 번호에 해당하는 문제를 삭제.//
    var forDel = document.getElementById("Prob" + number);
    localStorage.removeItem("Problem" + number);
    document.getElementById("DisplayList").removeChild(forDel);//문제 list화면에서 삭제//
    if (document.getElementById("DisplayProb").innerHTML != "") {//문제 출력 화면에서 삭제//
        forDel = document.getElementById("pN" + number);
        document.getElementById("DisplayProb").removeChild(forDel);
    }
}
//========================================================================//
function start() {
    document.getElementById("saveButton").addEventListener("click", Store, false);
    document.getElementById("NewProb").addEventListener("click", Create, false);
    document.getElementById("LoadProb").addEventListener("click", Display, false);
    if (localStorage.length != 0) {//localstorage에 기존에 문제가 만들어져 있으면
        for (var index = 0; index < localStorage.length; index++) {
            var pKey = localStorage.key(index);
            var pJSON = localStorage.getItem(pKey);
            var numOfProb = JSON.parse(pJSON).probNum;
            makeProbList(numOfProb);//이를 문제 list에 추가해서 불러올 수 있도록 한다.//
        }
    }
}
window.addEventListener("load", start, false);