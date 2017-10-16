/**
 * Created by murat on 2017-07-13.
 * Murat Ortak 125312157
 */

//import java.util.List;
//import java.util.Arrays;
//import java.util.Comparator;
//import java.util.List;
//import java.util.Map;
//import java.util.TreeMap;
//import java.util.function.Consumer;
//import java.util.function.BiConsumer;
import jdk.internal.org.objectweb.asm.tree.analysis.Value;

import java.util.Arrays;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StudentProcess {
   private static Student[] students = {
            new Student("Jack", "Smith", 50.0, "IT"),
            new Student("Aaron", "Johnson", 76.0, "IT"),
            new Student("Maaria", "White", 35.8, "Business"),
            new Student("John", "White", 47.0, "Media"),
            new Student("Laney", "White", 62.0, "IT"),
            new Student("Jack", "Jones", 32.9, "Business"),
            new Student("Wesley", "Jones", 42.89, "Media")};

    //		List<Integer>
   private static List<Student> student_list = Arrays.asList(students);

   public static void task1(){
       System.out.println("TASK 1\n");

            student_list.forEach(System.out::println);

       System.out.println("\n");
    }

    public static void task2(){
        System.out.println("TASK 2\n");
        System.out.println("Students who got 50.0-100.0 sorted by grade:\n");
        student_list.stream().filter(g->g.getGrade() >= 50)
                .sorted(Comparator.comparing(Student::getGrade))
                .forEach(s->System.out.println(s));

        System.out.println("\n");
    }

    public static void task3(){
        System.out.println("TASK 3\n");
        System.out.println("First Student who got 50.50-100.0:\n");
        Optional<Student> first_student = student_list.stream().filter(g->g.getGrade() >= 50)
//                .sorted(Comparator.comparing(Student::getGrade))
                .findFirst();

        System.out.println(first_student.get());
        System.out.println("\n");
    }

    public static void task4(){
        System.out.println("Task 4\n");
        System.out.println("\n------------------------------\n");
        System.out.println("Students in ascending order by last name then first:\n");
        System.out.println("------------------------------\n");

        student_list.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName))
                    .forEach(s->System.out.println(s));

        System.out.println("\n------------------------------\n");
        System.out.println("Students in descending order by last name then first:\n");
        System.out.println("------------------------------\n");

        student_list.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName).reversed())
                .forEach(s->System.out.println(s));

        System.out.println("\n");
    }

    public static void task5(){
        System.out.println("TASK 5\n");
        System.out.println("Unique Student last names:\n");
        student_list.stream().sorted(Comparator.comparing(Student::getLastName)).map(Student::getLastName).distinct()
                .forEach(s->System.out.println(s));

        System.out.println("\n");
    }

    public static void task6(){
        System.out.println("TASK 6\n");
        System.out.println("Student names in order by last name then first name:\n");
        student_list.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName)).map(Student::getName)
                .forEach(s->System.out.println(s));

        System.out.println("\n");

    }

    public static void task7(){
        System.out.println("TASK 7\n");
        System.out.println("Students by department\n");

            Map<String, List<Student>> map = student_list.stream().collect(Collectors.groupingBy(s->s.department));
            map.forEach((s, a) -> {
                System.out.print(s +"\n");
                a.forEach(q -> System.out.print("\t"+q));
            });

        System.out.println("\n");
    }

    public static void task8(){
        System.out.println("TASK 8\n");
        System.out.println("Count of Students by department:\n");
        Map<String, Long> map = student_list.stream().collect(Collectors.groupingBy(s->s.department, TreeMap::new, Collectors.counting()));
        map.forEach((s, a)->System.out.println(s + " has " + a + " Student(s)"));

        System.out.println("\n");
    }

    public static void task9(){
        System.out.println("TASK 9\n");

        Double grades = student_list.stream().mapToDouble(Student::getGrade).sum();
        System.out.println("Sum of Students' grades: " + grades+ "\n");

        System.out.println("\n");
    }

    public static void task10(){
        System.out.println("TASK 10\n");

        Double average = student_list.stream().mapToDouble(Student::getGrade).average().orElse(0.0);
        System.out.println("Average of Students' grades: " + average+ "\n");

        System.out.println("\n");
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        task1();
        task2();
        task3();
        task4();
        task5();
        task6();
        task7();
        task8();
        task9();
        task10();
   }

}

