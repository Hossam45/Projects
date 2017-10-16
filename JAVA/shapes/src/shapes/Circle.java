package shapes;

import java.io.IOException;

public class Circle implements Shape{


	double radius;


	public Circle(double r1) throws IOException {
		if(r1 <=0){
			throw new IOException("Radius is less than or equals to 0");
		}
		setR(r1);
	}

	public double getRadius(){
		return this.radius;
	}

	public void setR(double r){
		this.radius = r;
	}

	public double perimeter() {

		return 2 * radius * Math.PI;

	}

	@Override
	public String toString(){

		return "Circle {r = " + getRadius() +"} perimeter = " + perimeter()+"\n" ; 
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Circle other = (Circle) obj;
		if (radius != other.radius)
			return false;
		if (perimeter() != other.perimeter())
			return false;

		return true;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = (int) (prime * result + radius);
		result = (int) (prime * result + perimeter());
		return result;
	}



}


