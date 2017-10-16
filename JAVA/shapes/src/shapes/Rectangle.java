package shapes;

import java.io.IOException;

public class Rectangle extends Parallelogram{
	double width;
	double height;

	public Rectangle(double w, double h) throws IOException{
		super(w, h);
	}

	public double getWidth(){
		return this.width;
	}

	public double getHeight(){
		return this.height;
	}


	public void setWidth(double w){
		this.width = w;
	}

	public void setHeigth(double h){
		this.height = h;
	}

	public double perimeter() {
		return super.perimeter();
	}


	@Override
	public String toString(){

		return "Rectangle{lines=" + getWidth() + ", " + getHeight() +"} perimeter = " + perimeter()+"\n" ; 
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (this.getClass() != obj.getClass())
			return false;
		Rectangle other = (Rectangle) obj;
		if (this.width != other.width)
			return false;
		if (this.height != other.height)
			return false;
		if (perimeter() != other.perimeter())
			return false;

		return true;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = (int) (prime * result + this.width);
		result = (int) (prime * result + this.height);
		result = (int) (prime * result + perimeter());
		return result;
	}

}
