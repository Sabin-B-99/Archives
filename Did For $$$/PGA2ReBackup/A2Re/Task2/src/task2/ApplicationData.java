package task2;

import java.util.ArrayList;

/**
 * A singelton class that initializes the program's hardcoded data and stores those data
 * in temporary memory of the computer in an ArrayList
 */
public final class ApplicationData {
    
    private ApplicationData(){
    }

    /**
     * A static method that initializes the hardcoded data and stroes them in temporary memory in an
     * ArrayList whose refrence is passed as parameter to this method 
     * @param applicationData temprary memory/ ArrayList in which the program's initial hardcoded data is  stored 
     */
    public static void initializeData(ArrayList<Gym> applicationData){
        Gym gymI = new Gym("Mcgregor's Gym");
        Gym gymII = new Gym("People's Gym");
        Gym gymIII = new Gym("Jim's Gym");


        gymI.addTrainer("Conor Makachev");
        gymI.addTrainer("Khabib Mcgregor");
        gymI.addTrainer("Dustin Diaz");
        gymI.addTrainer("Nate Proirer");
        gymI.addTrainer("Kate Watson");
        gymI.addTrainer("Bill Windows");
        gymI.addTrainer("Naomi Smith");

        gymII.addTrainer("Biggie Bangs");
        gymII.addTrainer("Bille Chan");
        gymII.addTrainer("Kathy Simmons");
        gymII.addTrainer("Renee Dominique");
        gymII.addTrainer("Emma Elizabeth");
        gymII.addTrainer("Peter Michaels");
        gymII.addTrainer("Kylie West");

        gymIII.addTrainer("Saroj Tiwari");
        gymIII.addTrainer("Joshua Knight");
        gymIII.addTrainer("Forrest Fluke");
        gymIII.addTrainer("Billy Jean");
        gymIII.addTrainer("Annie Isaokay");
        gymIII.addTrainer("David Hallden");
        gymIII.addTrainer("Linis Allen");

        gymI.addMember("John Doe");
        gymI.addMember("Jane Doe");
        gymI.addMember("Linda Johnson");
        gymI.addMember("Paul Mcgregor");
        gymI.addMember("Simon Green");
        gymI.addMember("Kathy Indiana");
        gymI.addMember("Kyle Smith");
        gymI.addMember("Morty Sanchez");
        gymI.addMember("Kale Pale");
        gymI.addMember("Dakota White");
        gymI.addMember("Jeniffer Jhonson");
        gymI.addMember("Chandler Kumar");
        gymI.addMember("Joey Aniston");
        gymI.addMember("David Ross");
        gymI.addMember("Jack Chan");
        gymI.addMember("Bill Ma");
        gymI.addMember("Steve Gates");
        gymI.addMember("Mark Hooman");
        gymI.addMember("Barry Page");
        gymI.addMember("Christina Orangegate");
        gymI.addMember("Kylie Cuckoo");
        gymI.addMember("Harry Undertaker");
        gymI.addMember("Thomas Neuer");
        gymI.addMember("Amanda Perry");
        gymI.addMember("Sabine Gurung");

        gymII.addMember("Kathy Berry");
        gymII.addMember("Raj Mysterio");
        gymII.addMember("George Fanning");
        gymII.addMember("Paul Mcarthy");
        gymII.addMember("Dana Black");
        gymII.addMember("Abdul Kalam");
        gymII.addMember("Malak Ansari");
        gymII.addMember("Raheem Pogba");
        gymII.addMember("Pineapple Pizza");
        gymII.addMember("Elizabeth Simmions");
        gymII.addMember("Emma Bjornson");
        gymII.addMember("Eric Carter");
        gymII.addMember("Kenny Rodriguez");
        gymII.addMember("Luis Ronaldo");
        gymII.addMember("Robert Lewangolski");
        gymII.addMember("Elon XAE-12");
        gymII.addMember("Wan Ki Moon");
        gymII.addMember("Vladimir Rostov");
        gymII.addMember("Donald Biden");
        gymII.addMember("Xi Jin Modi");
        gymII.addMember("Emma Nakarmi");
        gymII.addMember("Naomi Watts");
        gymII.addMember("Amamnda Cerny");
        gymII.addMember("Nuna Gomez");
        gymII.addMember("Mario Pellegroni");


        gymIII.addMember("Maria Pepe");
        gymIII.addMember("Dustin Doe");
        gymIII.addMember("Bastian Ballack");
        gymIII.addMember("Ryan Watson");
        gymIII.addMember("Lord Voldemort Potters");
        gymIII.addMember("Jerry Thomas");
        gymIII.addMember("Anastia Kirliovna");
        gymIII.addMember("Silas Langdon");
        gymIII.addMember("Robert Sinclair");
        gymIII.addMember("Bezu Fache");
        gymIII.addMember("Steve Collet");
        gymIII.addMember("Bojack Horseman");
        gymIII.addMember("Butters Grounded");
        gymIII.addMember("Stan Mcormick");
        gymIII.addMember("Kenny Goodheart");
        gymIII.addMember("Jenny Penny");
        gymIII.addMember("Jennifer Watson");
        gymIII.addMember("Kaskha Taylor");
        gymIII.addMember("Larry Brim");
        gymIII.addMember("Reyna Sage");
        gymIII.addMember("Laura Bee");
        gymIII.addMember("Luna Mendes");
        gymIII.addMember("Lex Luthor");
        gymIII.addMember("Lionel Martinez");
        gymIII.addMember("Dustin Doe");

        gymI.takeClassSession("Zumba", 14, 10, 12, 7, 30);
        gymI.takeClassSession("Yoga", 6, 10, 12, 17, 30);
        gymI.takeClassSession("Pilates", 24, 11, 18, 5, 15);
        gymI.takeClassSession("Body Balance", 18, 11, 17, 9, 45);


        gymII.takeClassSession("Zumba", 4, 10, 13, 12, 30);
        gymII.takeClassSession("Yoga", 8, 8, 12, 11, 15);
        gymII.takeClassSession("Pilates", 19, 11, 17, 5, 15);
        gymII.takeClassSession("Body Balance", 35, 11, 17, 9, 45);


        gymIII.takeClassSession("Zumba", 4, 7, 7, 7, 10);
        gymIII.takeClassSession("Yoga", 3, 9, 24, 13, 15);
        gymIII.takeClassSession("Pilates", 12, 5, 15, 5, 15);
        gymIII.takeClassSession("Body Balance", 8, 11, 11, 11, 11);



        applicationData.add(gymI);
        applicationData.add(gymII);
        applicationData.add(gymIII);
    }
}
