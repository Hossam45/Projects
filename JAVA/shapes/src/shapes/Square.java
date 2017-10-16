package shapes;

import java.io.IOException;
public class Square extends Rectangle {

	double side;

	public Square(double s) throws IOException{
		super(s, s);
	}

	public double getSide(){
		return this.side;
	}

	public void setSide(double s){
		this.side = s;
	}

	public double perimeter() {
		return super.perimeter();
	}

	@Override
	public String toString(){

		return "Square{line=" + getSide() +"} perimeter = " + perimeter() + "\n" ; 
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (this.getClass() != obj.getClass())
			return false;
		Square other = (Square) obj;
		if (this.side != other.side)
			return false;
		if (perimeter() != other.perimeter())
			return false;

		return true;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = (int) (prime * result + side);
		result = (int) (prime * result + perimeter());
		return result;
	}

}
