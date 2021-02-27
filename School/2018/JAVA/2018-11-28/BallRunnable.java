import java.awt.Component;

class BallRunnable implements Runnable{
	public BallRunnable(Ball aBall, Component aComponent) {
		ball = aBall; component = aComponent;
	}
	public void run() {
		try {
			for(int i = 1; i <= STEPS; i++) {
				ball.move(component.getBounds());
				component.repaint();
				Thread.sleep(DELAY);
			}
		}catch (InterruptedException e) {}
	}
	private Ball ball;
	private Component component;
	public static final int STEPS = 100000000; //공이 움직이는 횟수
	public static final int DELAY = 5; //공의 속도 조절 여기가 수정되어야함!
}
//ball that