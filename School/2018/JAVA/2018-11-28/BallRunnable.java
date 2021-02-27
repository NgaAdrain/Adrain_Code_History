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
	public static final int STEPS = 100000000; //���� �����̴� Ƚ��
	public static final int DELAY = 5; //���� �ӵ� ���� ���Ⱑ �����Ǿ����!
}
//ball that