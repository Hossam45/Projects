package shapes;

import java.io.IOException;

public class Triangle implements Shape{

	double side1, side2, side3;


	public Triangle(double s1, double s2, double s3) throws IOException{
		if(s1 <= 0.0 || s2 <= 0.0 || s3 <= 0.0){
			throw new IOException("TRIANGLE One of the sides is less than or equals to 0");
		}

		setLine(s1, s2,s3);
	}

	public double getSide1(){
		return this.side1;
	}

	public double getSide2(){
		return this.side2;
	}

	public double getSide3(){
		return this.side3;
	}



	public void setLine(double l1, double l2, double l3){
		this.side1 = l1;
		this.side2 = l2;
		this.side3 = l3;
	}

	public double perimeter() {
		return side1 + side2 + side3;

	}

	@Override
	public String toString(){

		return "Triangle{lines=" + getSide1() + ", " + getSide2() + ", " + getSide3() +"} perimeter = " + perimeter()+"\n" ; 

	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Triangle other = (Triangle) obj;
		if (this.perimeter() != other.perimeter())
			return false;

		return true;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = (int) (prime * result + perimeter());
		return result;
	}

}
