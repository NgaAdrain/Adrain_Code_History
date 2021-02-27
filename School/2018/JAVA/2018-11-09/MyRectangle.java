package pnu;
public class MyRectangle {
	private int wid,height;
	public MyRectangle() {
		this.wid = 0;
		this.height = 0;
	}
	public MyRectangle(int wid, int height){
		this.wid = wid;
		this.height = height;
	}
	public int getWide() {
		return wid;
	}
	
	public int getHeight(){
		return height;
	}

	public String toString() {
			String msg;
			msg =  "Rectangle: width " + this.wid + ", height " + this.height ;
			return msg;
	}
}
