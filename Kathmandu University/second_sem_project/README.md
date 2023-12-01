# second_sem_project
Repository containing source codes for second semester project at Kathmandu University.
Project aims to create a simple recommendation system and use it to recommend restaurants in a 
simple console program that tries to simulate a 'Restaurant Recommender app'.


The project is incomplete but is still runnable and has missing fatures.

# Restaurant data set
Zomato Restaurants Data. Found in Kaggle. 
https://www.kaggle.com/shrutimehta/zomato-restaurants-data

# Extenal dependencies used till date:
sqlite3 database c/c++ connector library (https://www.sqlite.org/cintro.html)
OpenSSL (https://www.openssl.org/) - for cryptographic functions 

# External dependecies that will be used:
mlpack (https://www.mlpack.org/) - to develop the recommendation system

# important works to be completed 
proper comments and documentation of the code
integration of the recommendation system into the program.

# Instruction before building the repository:
Before building this repository from your local machine download the precomiled 
OpenSSL form the google drive link mentioned here:
https://drive.google.com/drive/folders/1rcQCD-g8yC8AnVCPm-1HzTbhnX6zAhas?usp=sharing
Then add the folder named OpenSSL 1.1.1 in the drive to the project folder.
This 'OpenSSL 1.1.1' folder should be placed inside External Dependencies folder of the project
folder. Initally there is no folder named External Dependencies inside the project folder. So, you 
should create one yourself.
Once this is will be able to build the project without any errors. :)

Similarly, download the sqlite-amalgamation-3320300 folder available in the above google drive 
link and add that downloaded folder into the same External Dependencies folder as before. 