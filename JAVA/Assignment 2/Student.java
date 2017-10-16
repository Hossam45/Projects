/**
 * Created by murat on 2017-07-13.
 */


public class Student {

    String firstName;
    String lastName;
    double grade;
    String department;

    public Student(String name, String lastName, double gr, String dept){
        this.firstName = name;
        this.lastName = lastName;
        this.grade = gr;
        this.department = dept;
    }

    public String getFirstName(){
        return this.firstName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public double getGrade(){
        return this.grade;
    }

    public String getDepartment(){
        return this.department;
    }

    public void setFirstName(String name){
        this.firstName = name;
    }

    public void setLastName(String lastName){
        this.lastName = lastName;
    }

    public void setGrade(double grade){
        this.grade = grade;
    }

    public void setDepartment(String department){
        this.department = department;
    }

    public String getName(){
        return firstName+" "+lastName;
    }

    public String toString(){
        return getName()+" "+getGrade()+" "+ getDepartment()+"\n";
    }

    public int hashCode(){
            final int prime = 31;
            int result = 1;
            result = prime * result + (int) getGrade();
            result = prime * result + ((getFirstName() == null) ? 0 : getFirstName().hashCode());
            result = prime * result + ((getLastName() == null) ? 0 : getLastName().hashCode());
            result = prime * result + ((getDepartment() == null) ? 0 : getDepartment().hashCode());
            return result;
    }

    public boolean equals(Object obj){
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Student other = (Student) obj;
        if (getGrade() != other.getGrade())
            return false;
        if (getFirstName() == null) {
            if (other.getFirstName() != null)
                return false;
        } else if (!getFirstName().equals(other.getFirstName()))
            return false;
        if (getLastName() == null) {
            if (other.getLastName() != null)
                return false;
        } else if (!getLastName().equals(other.getLastName()))
            return false;
        if (getDepartment() == null) {
            if (other.getDepartment() != null)
                return false;
        } else if (!getDepartment().equals(other.getDepartment()))
            return false;
        return true;
    }
}

