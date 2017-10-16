package shapes;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class main {
	static Shape[] shape_last = new Shape[100]; 
	public static Shape[] task1(String args){

		int count = 0;
		int item_count = 0;
		try (BufferedReader br = new BufferedReader(new FileReader(args))) {
			String s1;
			while ((s1 = br.readLine()) != null) {
				count++;
			}
			br.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}


		Shape[] shapes = new Shape[count+1];
		try (BufferedReader br = new BufferedReader(new FileReader(args))) {
			String s;
			double line1 = 0;
			double line2 = 0, line3 = 0;

			double r;
			while ((s = br.readLine()) != null) {
				String[] tokens = s.split(",");

				if((tokens.length == 2) && (tokens[0].equals("Square") || tokens[0].equals("Circle"))){

					line1 = Double.parseDouble(tokens[1]);
				}else if(tokens.length == 3 && (tokens[0].equals("Rectangle") || tokens[0].equals("Parallelogram"))){
					line1 = Double.parseDouble(tokens[1]);
					line2 = Double.parseDouble(tokens[2]);
				}else if(tokens.length == 4 && (tokens[0].equals("Triangle"))){
					line1 = Double.parseDouble(tokens[1]);
					line2 = Double.parseDouble(tokens[2]);
					line3 = Double.parseDouble(tokens[3]);
				}

				//your code
				if((tokens[0].equals("Rectangle")) && (tokens[0].length() == 3) ){
					try{
						Shape r2 = new Rectangle(line1, line2);
						for(int i = 0; i < count; i++){
							if(shapes[i] == null){
								shapes[i] = r2;
								item_count++;
								break;
							}
						}
					}catch(IOException e){
						System.out.println(e.getMessage());
					}
				}else if(tokens[0].equals("Circle")){
					try{
						Shape c = new Circle(line1);
						for(int i = 0; i < count; i++){
							if(shapes[i] == null){
								shapes[i] = c;
								item_count++;
								break;
							}
						}
					}catch(IOException e){
						System.out.println(e.getMessage());
					}
				}
				else if(tokens[0].equals("Parallelogram")){
					try{
						Shape p = new Parallelogram(line1, line2);
						for(int i = 0; i < count; i++){
							if(shapes[i] == null){
								shapes[i] = p;
								item_count++;
								break;
							}
						}
					}catch(IOException e){
						System.out.println(e.getMessage());
					}

				}else if(tokens[0].equals("Square")){
					try{
						Shape s2 = new Square(line1);
						for(int i = 0; i < count; i++){
							if(shapes[i] == null){
								shapes[i] = s2;
								item_count++;
								break;
							}
						}
					}catch(IOException e){
						System.out.println(e.getMessage());
					}
				}else if(tokens[0].equals("Triangle")){
					try{
						Shape t = new Triangle(line1, line2, line3);
						for(int i = 0; i < count; i++){
							if(shapes[i] == null){
								shapes[i] = t;
								item_count++;
								break;
							}
						}
					}catch(IOException e){
						System.out.println(e.getMessage());
					}
				}
			}
			br.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} 

		Shape[] new_s = new Shape[item_count];
		for(int i = 0; i < item_count; i++){
			new_s[i] = shapes[i];
		}
		System.out.println("Total item in the array before the deletion is: " + new_s.length);
		return new_s;
	}
	public static void task2(Shape[] shapes){
		double t_min = 0.0, c_max = 0.0;
		int t_count = 0, c_count = 0, deleted_count = 0;
		double[] t_perimeters = new double[100];
		double[] c_perimeters = new double[10];
		Shape deleted[] = new Shape[10];
		int len = shapes.length;
		for(Shape p : shapes){
			if(p.getClass().getName().equals("shapes.Triangle")){
				for(int i = 0; i <= t_perimeters.length; i++){
					if(t_perimeters[i] == 0){
						t_perimeters[i] = p.perimeter();
						t_count++;
						break;
					}
				}
				for(int i = 0; i < t_count; i++){
					double min1 = t_perimeters[0];
					if(t_perimeters[i] <= min1){
						t_min = t_perimeters[i];
					}
				}
			}else if(p.getClass().getName().equals("shapes.Circle")){
				for(int i = 0; i < c_perimeters.length; i++){
					if(c_perimeters[i] == 0){
						c_perimeters[i] = p.perimeter();
						c_count++;
						break;
					}
				}
				for(int i = 0; i < c_count; i++){
					double min1 = c_perimeters[0];
					if(c_perimeters[0] >= min1){
						c_max = c_perimeters[0];
					}
				}
			}
		}
		for(int i = 0; i < len; i++){

			if(shapes[i].getClass().getName().equals("shapes.Triangle") && shapes[i].perimeter() == t_min){
				for(int i1 = 0; i1 < t_count; i1++){
					if(deleted[i1] == null){
						deleted[i1] = shapes[i];
						deleted_count++;
						break;
					}
				}
				shapes[i] = null;
				for(int j = i+1; j < shapes.length; j++){
					shapes[j-1] = shapes[j];
				}
				len--;
				shapes[len] = null;
			}else if(shapes[i].getClass().getName().equals("shapes.Circle") && shapes[i].perimeter() == c_max){
				for(int i1 = 0; i1 < t_count; i1++){
					if(deleted[i1] == null){
						deleted[i1] = shapes[i];
						deleted_count++;
						break;
					}
				}
				shapes[i] = null;
				for(int j = i+1; j < shapes.length; j++){
					shapes[j-1] = shapes[j];
				}
				len--;
				shapes[len] = null;
			}
		}
		Shape[] new_s = new Shape[len];
		for(int i = 0; i < len; i++){
			new_s[i] = shapes[i];
		}
		for(Shape s : new_s){
			System.out.println(s.toString());
		}
		
		System.out.println("Total item after deletion is: " + len);
		System.out.println("Total deleted item is: " + deleted_count);
		System.out.println("Deleted Items are: \n");
		for(int i = 0; i < deleted_count; i++){
			System.out.println(deleted[i].toString());
		}
	}
	public static void task3(Shape[] s){
		double p_total = 0.0, t_total = 0.0;
		for(Shape p : s){
			if(p.getClass().getName().equals("shapes.Parallelogram")){
				p_total += p.perimeter();
			}else if(p.getClass().getName().equals("shapes.Triangle")){
				t_total += p.perimeter();
			}
		}

		System.out.println("Total of parallelogram is: " + p_total + "\n" + "Total of triangles is: " + t_total);
	}

	public static void main(String[] args) {

		task2(task1(args[0]));
		task3(task1(args[0]));
	}

}
