#include<bits/stdc++.h>
using namespace std;
class player {
public:
    struct node {
        string name, p_type;

        string wc_played, matches,runs, wickets;
        node* next;
    };

    node* head = nullptr;


    // Function to display a menu for interacting with the player database
    void menu() {
        while (true) {
            cout << "-------Menu:-------\n" << endl;
            cout << "1. Add a player" << endl;
            cout << "2. Search " << endl;
            cout << "3. Update player information" << endl;
            cout << "4. Delete a player" << endl;
            cout << "5. Display All Players." << endl;
            cout << "6. Exit\n" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    insert();
                    break;
                case 2:
                    search();
                    break;
                case 3:
                    update();
                    break;
                case 4:
                    del();
                    break;
                case 5:
                    display();
                    break;
                case 6:
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }


        // Function to insert a new player into the database
    void insert(){

        cout<<"-----In Which Team You Want To Add A Player?-----\n";

        cout<<"1. Afganistan \n2. Australia \n3. England \n4. Netehrland \n5. Bangladesh\n";
        cout<<"6. India \n7. New Zealand \n8. Pakistan \n9. South Africa \n10. Srilanka\n";

        int teamChoice;
        cin>>teamChoice;

        fstream file;

        if(teamChoice==1){       //  for afganistan
        file.open("Afganistan.txt", ios::app);

        }else if(teamChoice==2){   //for australia

        file.open("Australia.txt", ios::app);

      }else if(teamChoice==3){    //for england
        file.open("England.txt", ios::app);

      }else if(teamChoice==4){    //for Netherland

         file.open("Netherland.txt", ios::app);
      }else if(teamChoice==5){    //for bangladesh
         file.open("Bangladesh.txt", ios::app);

      }else if(teamChoice==6){     //for India
         file.open("India.txt", ios::app);

      }else if(teamChoice==7){     //for New Zealand
         file.open("New Zealand.txt", ios::app);

      }else if(teamChoice==8){     //for Pakistan
         file.open("Pakistan.txt", ios::app);

      }else if(teamChoice==9){     //for South Africa
         file.open("South Africa.txt", ios::app);

      }else if(teamChoice==10){     //for Srilanka
         file.open("Srilanka.txt", ios::app);

      }else{
          cout<<"You Have choosen Invalid Option!\n";
          cout<<"Would You like to Try Again?(y/n): ";
          char validity;

           cin>>validity;
          if(validity=='y'){
            insert();
          }else{
             menu();
          }
      }

       node* newPlayer = new node;

        cout<<"Enter name: ";
        cin.ignore();
        getline(cin, newPlayer->name);
        string Name=newPlayer->name;   //transforms the playing role to upper case and removing internal spaces
        transform(Name.begin(), Name.end(), Name.begin(), ::toupper);
        Name.erase(remove(Name.begin(), Name.end(), ' '), Name.end());
        newPlayer->name=Name;


        cout<<"\nEnter Attended World Cup: ";
        cin >> newPlayer->wc_played;

        cout<<"\nEnter Playing role: ";
        cin.ignore();
        getline(cin, newPlayer->p_type);
        string role=newPlayer->p_type;   //transforms the playing role to upper case and removing internal spaces
        transform(role.begin(), role.end(), role.begin(), ::toupper);
        role.erase(remove(role.begin(), role.end(), ' '), role.end());
        newPlayer->p_type=role;


        cout<<"\nEnter Played Matches: ";
        cin >> newPlayer->matches;

        cout<<"\nEnter Runs: ";
        cin >> newPlayer->runs;

        cout<<"\nEnter Played Wickets: ";
        cin >> newPlayer->wickets;

        file<<"\n"<<newPlayer->name<<" "<<newPlayer->wc_played<<" "<<newPlayer->p_type<<" "<<newPlayer->matches<<" "<<newPlayer->runs<<" "<<newPlayer->wickets;

        file.close();

    }


    // Function to update player information
        void update()
    {
        fstream file;

        cout << "-----Select the team-----\n";
        cout << "1. Afganistan \n2. Australia \n3. England \n4. Netherland \n5. Bangladesh\n";
        cout << "6. India \n7. New Zealand \n8. Pakistan \n9. South Africa \n10. Srilanka\n";

        int teamChoice;
        cin >> teamChoice;

        string teamFileName;

        // Define the file name based on the team choice
        switch (teamChoice)
        {
        case 1:
            teamFileName = "Afganistan.txt";
            break;
        case 2:
            teamFileName = "Australia.txt";
            break;
        case 3:
            teamFileName = "England.txt";
            break;
        case 4:
            teamFileName = "Netherland.txt";
            break;
        case 5:
            teamFileName = "Bangladesh.txt";
            break;
        case 6:
            teamFileName = "India.txt";
            break;
        case 7:
            teamFileName = "New Zealand.txt";
            break;
        case 8:
            teamFileName = "Pakistan.txt";
            break;
        case 9:
            teamFileName = "South Africa.txt";
            break;
        case 10:
            teamFileName = "Srilanka.txt";
            break;
        default:
        {
            cout<<"You Have choosen Invalid Option!\n";
            cout<<"Would You like to Try Again?(y/n): ";
            char validity;

            cin>>validity;
            if(validity=='y')
            {
                update();
            }
            else
            {
                cout<<endl<<endl;
                menu();
            }

        }

        }



        file.open(teamFileName, ios::in);//For Reading into the file

        if (!file.is_open())
        {
            cout << "Error opening the file!" << endl;
            cout<<"Would You like to Try Again?(y/n): ";
            char validity;

            cin>>validity;
            if(validity=='y'||validity=='Y')
            {
                update();
            }
            else
            {
                cout<<endl<<endl;
                menu();
            }


        }

        // Reading the player's info from the file into a linked list
        node* playerList = nullptr;
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            node* updatedPlayer = new node;
            if (iss >> updatedPlayer->name >> updatedPlayer->wc_played >> updatedPlayer->p_type >> updatedPlayer->matches >> updatedPlayer->runs >> updatedPlayer->wickets)
            {
                updatedPlayer->next = playerList;
                playerList = updatedPlayer;
            }
        }
        file.close();

        string targetName;
        cout << "Enter the name of the player you want to update: ";
        cin.ignore();
        getline(cin, targetName);

        // TO Find and update the player's info in the linked list
        node* updatedInfo = playerList;
        while (updatedInfo != nullptr)
        {
            if (updatedInfo->name == targetName)
            {
                cout << "Enter updated played matches: ";
                cin >> updatedInfo->matches;

                cout << "Enter updated runs: ";
                cin >> updatedInfo->runs;

                cout << "Enter updated played wickets: ";
                cin >> updatedInfo->wickets;
                break; // Player found and updated, exit the loop
            }
            updatedInfo = updatedInfo->next;
        }

        if (updatedInfo == nullptr)
        {
            cout << "Player not found!" << endl;
            cout<<"Would You like to Try Again?(y/n): ";
            char validity;

            cin>>validity;
            if(validity=='y'||validity=='Y')
            {
                update();
            }
            else
            {
                cout<<endl<<endl;
                menu();
            }
        }
        else
        {
            // TO Write the updated linked list back to the file
            file.open(teamFileName, ios::out);

            updatedInfo = playerList;
            while (updatedInfo != nullptr)
            {
                file << updatedInfo->name << " " << updatedInfo->wc_played << " " << updatedInfo->p_type << " " << updatedInfo->matches << " " << updatedInfo->runs << " " << updatedInfo->wickets << endl;
                node* temp = updatedInfo;
                updatedInfo =updatedInfo->next;
                delete temp;
            }
            file.close();
            cout << "Player information updated successfully!" << endl;
            cout<<"Would You like to update a player again?(y/n): ";
            char validity;

            cin>>validity;
            if(validity=='y'||validity=='Y')
            {
                update();
            }
            else
            {
                cout<<endl<<endl;
                menu();
            }

        }

        cout<<endl<<endl;
        menu();
    }

    // Function to search for a player
    void search() {

       cout<<"-------Which You Want to Search?-------";
       cout<<"\n1. Full Squad of A Country \n2. Informations of a player \n3. Attended World Cup of a Player\n4. Runs of a Player.\n";
       cout<<"5. Wickets of A Bowler.\n6. Number of Matches one Played\n";
       int searchOption;
       cin>>searchOption;

       if(searchOption==1){
           fullSquadSearch();

       }else if(searchOption==2){
            allSearches(2);  //for information of a player
       }else if(searchOption==3){
            allSearches(3);   //for attended world cup
       }else if(searchOption==4){
            allSearches(4); //for run of a player
       }else if(searchOption==5){
            allSearches(5); //for wickets
       }else if(searchOption==6){
             allSearches(6);  //how many matches a player played
       }




       else{
          cout<<"You Have choosen Invalid Option!\n";
          cout<<"Would You like to Try Again?(y/n): ";
          char validity;

           cin>>validity;
          if(validity=='y'){
            search();
          }else{
             menu();
          }
      }

    }



    void allSearches(int searchOption){

    fstream file;
    string line,name, targetedName, wcAttended, playingRole, matches, runs, wickets;


    cout<<"All the Letter Should Be Uppecase without Space\n";
    cout<<"Enter the Player Name: ";
    cin.ignore();

   getline(cin, targetedName);



    transform(targetedName.begin(), targetedName.end(), targetedName.begin(), ::toupper);
    //if mistakenly user provide any space, it will remove the spaces
    targetedName.erase(remove(targetedName.begin(), targetedName.end(), ' '), targetedName.end());


    string fileArr[]={"Afganistan.txt", "Australia.txt", "Bangladesh.txt" ,"England.txt", "India.txt", "Netherland.txt", "New Zealand.txt", "Pakistan.txt", "South Africa.txt", "Srilanka.txt",};


    for(int i=0; i<10; i++){

    file.open(fileArr[i]);


    while(getline(file, line)){
        istringstream iss(line);

        if(iss >> name >> wcAttended >> playingRole >> matches >> runs >> wickets){
              if(targetedName==name){

                if(searchOption==3){  //for attended world cup
                  cout<<"Name: "<<name<<"    Attended World Cup: "<<wcAttended<<endl;


                   cout<<"Would You like to Search Again?(y/n): ";
                   char validity;

                   cin>>validity;
                   if(validity=='y'){
                       allSearches(3);
                  }else{
                       menu();
                   }

                }else if(searchOption==2){  //for searching all the information of a player
                   cout<<"Name:"<<name<<"      World Cup Attended:"<<wcAttended<<"   Role:"<<playingRole<<"    Matches:"<<matches<<"    Runs:"<<runs<<"   Wickets"<<wickets<<endl;
                   cout<<"Would You like to Search Again?(y/n): ";
                   char validity;

                   cin>>validity;
                   if(validity=='y'){
                       allSearches(2);
                  }else{
                       menu();
                   }

                }else if(searchOption==4){  //for runs of a particular player
                     cout<<"Name:"<<name<<"  Total Runs:"<<runs<<endl;
                     cout<<"Want to See Other's Run?(y/n): ";
                   char validity;

                   cin>>validity;
                   if(validity=='y'){
                       allSearches(4);
                  }else{
                       menu();
                   }

                 }else if(searchOption==5){  //wicktes of a particular player
                     if(wickets=="NA"){
                        cout<<"Batter. So, have no wickets."<<endl;
                     }else{
                      cout<<"Name:"<<name<<"  Total Wickets:"<<wickets<<endl;
                      cout<<"Want to See Other's Wickets?(y/n): ";
                      char validity;

                      cin>>validity;
                      if(validity=='y'){
                       allSearches(5);
                      }else{
                         menu();
                       }
                   }
                 }
                 else if(searchOption==6){  //total world cup matches played
                       cout<<"Name:"<<name<<"  Total Matches:"<<matches<<endl;
                      cout<<"Want to See One's Total Matches?(y/n): ";
                      char validity;

                      cin>>validity;
                      if(validity=='y'){
                       allSearches(6);
                      }else{
                         menu();
                       }
                 }

            }

        }
    }
    file.close();
   }


}


    void fullSquadSearch(){
                 cout<<"-----Which Team You Want To See?-----\n";

        cout<<"1. Afganistan \n2. Australia \n3. England \n4. Netehrland \n5. Bangladesh\n";
        cout<<"6. India \n7. New Zealand \n8. Pakistan \n9.South Africa \n10. Srilanka\n";

        int teamChoice;
        cin>>teamChoice;

        fstream file;

        if(teamChoice==1){       //  for afganistan
        file.open("Afganistan.txt");

        }else if(teamChoice==2){   //for australia

        file.open("Australia.txt");

      }else if(teamChoice==3){    //for england
        file.open("England.txt");

      }else if(teamChoice==4){    //for Netherland

         file.open("Netherland.txt");
      }else if(teamChoice==5){    //for bangladesh
         file.open("Bangladesh.txt");

      }else if(teamChoice==6){     //for India
         file.open("India.txt");

      }else if(teamChoice==7){     //for New Zealand
         file.open("New Zealand.txt");

      }else if(teamChoice==8){     //for New Zealand
         file.open("Pakistan.txt");

      }else if(teamChoice==9){     //for New Zealand
         file.open("South Africa.txt");

      }else if(teamChoice==10){     //for New Zealand
         file.open("Srilanka.txt");

      }else{
          cout<<"You Have choosen Invalid Option!\n";
          cout<<"Would You like to Try Again?(y/n): ";
          char validity;

           cin>>validity;
          if(validity=='y'){
            fullSquadSearch();
          }else{
             menu();
          }

    }

    string line, name, wcAttended, playingRole, matches, runs, wickets;


    while(getline(file, line)){
       istringstream iss(line);
       if(iss >> name >> wcAttended >> playingRole >> matches >> runs >> wickets){
               cout<<"Name:"<<name<<"      World Cup Attended:"<<wcAttended<<"   Role:"<<playingRole<<"    Matches:"<<matches<<"    Runs:"<<runs<<"   Wickets"<<wickets<<endl;

    }

  }
}

    // Function to delete a player
        void del() {

       cout<<"              From which team you want to delete?   \n";


      cout<<"1. Afganistan \n2. Australia \n3. England \n4. Netehrland \n5. Bangladesh\n";
        cout<<"6. India \n7. New Zealand \n8. Pakistan \n9. South Africa \n10. Srilanka\n";
      int teamChoice;
     cin>>teamChoice;
    cout<<"All the Letters Should be Uppercase Without Space."<<endl;
    cout<<  "Enter the name of the player you want to delete: ";
    string p_del;
    cin>>p_del;

string teamFileName;
     ofstream tempFile;
     tempFile.open("temp.txt");

     ifstream read;
      if(teamChoice==1){       //  for afganistan
        read.open("Afganistan.txt");

         teamFileName="Afganistan.txt";
        }else if(teamChoice==2){   //for australia

        read.open("Australia.txt");
        teamFileName="Australia.txt";

      }else if(teamChoice==3){    //for england
        read.open("England.txt");
          teamFileName="England.txt";
      }else if(teamChoice==4){    //for Netherland

         read.open("Netherland.txt");

          teamFileName="Netherland.txt";


      }else if(teamChoice==5){    //for bangladesh
         read.open("Bangladesh.txt");
          teamFileName="Bangladesh.txt";


      }else if(teamChoice==6){     //for India
         read.open("India.txt");
          teamFileName="India.txt";

      }else if(teamChoice==7){     //for New Zealand
         read.open("New Zealand.txt");
          teamFileName="New Zealand.txt";

      }else if(teamChoice==8){     //for New Zealand
         read.open("Pakistan.txt");
         teamFileName="Pakistan.txt";

      }else if(teamChoice==9){     //for New Zealand
         read.open("South Africa.txt");

          teamFileName="South Africa.txt";


      }else if(teamChoice==10){     //for New Zealand
         read.open("Srilanka.txt");
          teamFileName="Srilanka.txt";

      }else{
          cout<<"You Have choosen Invalid Option!\n";
          cout<<"Would You like to Try Again?(y/n): ";
          char validity;

           cin>>validity;
          if(validity=='y'){
            insert();
          }else{
             menu();
          }
      }


    if(!read){
            cout<<"ERROR:File did not open! ";
            return;
        }


     string readline;  //for reading the file line by line
    bool p_found=false;

    while(getline(read,readline)){

        istringstream gett(readline);
        string name,age,p_type,matches;
        if(gett>>name>>age>>p_type>>matches){
            if(name==p_del){
                     cout << "Player found: " << name << " Age: " << age << " Type: " << p_type<< " World Cup Matches: " << matches << endl;
                p_found=true;
            }
            else{
                tempFile<<readline<<endl;
            }
        }


    }
     tempFile.close();
        read.close();



       if(p_found){
             remove(teamFileName.c_str());
              rename("temp.txt",teamFileName.c_str());
               cout << "Player " << p_del << " has been successfully deleted." << endl;
               menu();
              // exit(1);


        }
       else
        {
            cout<<"Could not find this name ";
            remove("temp.txt");
        }


    }


    void display()

    {
        cout<< "-----Want to see Display of ?-----"<<endl;
        cout<< "1. All players with most runs\n2. All players with most wickets\n3. All players who are captain"<<endl;

        int displayOpt;
        cin>> displayOpt;
    }




};

int main() {
    player database;
    database.menu();
    return 0;
}
