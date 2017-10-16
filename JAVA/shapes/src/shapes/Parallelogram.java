package shapes;

import java.io.IOException;

public class Parallelogram implements Shape{

	double width;
	double height;

	public Parallelogram(double w, double h)throws IOException{
		if(w <= 0 || h <=0){
			throw new IOException("PARAL One of the sides is less than or equals to 0");
		}
		this.width = w;
		this.height = h;
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

	public void setHeight(double h){
		this.height = h;
	}

	public double perimeter() {

		return 2*(width+height);
	}


	@Override
	public String toString(){

		return "Parallelogram{lines=" + getWidth() + ", " + getHeight() +"} perimeter = " + perimeter()+"\n" ; 
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Parallelogram other = (Parallelogram) obj;
		if (width != other.width)
			return false;
		if (height != other.height)
			return false;
		if (perimeter() != other.perimeter())
			return false;

		return true;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = (int) (prime * result + width);
		result = (int) (prime * result + height);
		result = (int) (prime * result + perimeter());
		return result;
	}

}
