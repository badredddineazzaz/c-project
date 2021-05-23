#include <iostream>
#include <fstream>
#include <string>

using namespace std;

 main()
{


    //Declarations :
ifstream htmlFile("htmlFile.txt");
ofstream resultFile("resultat.txt");

char character;
string result;
int choix;




//Fonction qui supprime les balises

	while (!htmlFile.eof()){
		htmlFile.get(character);

		if (character == '<')
                htmlFile.ignore(256, '>');

        if (character != '<')
                result += character;
    }


//Verifier si le fichier est vide ou non :

    if(htmlFile.is_open())
    {
        htmlFile.seekg(0,ios::end);
        size_t size = htmlFile.tellg();
        if( size == 0) // le fichier est vide
        {
             cout << "Le fichier est vide ! \nEntrez votre code html dans le ficher : \"htmlFile\", puis reessayer.\n";
        }
        else{ //le fichier n'est pas vide


            cout<< "*********** Bienvenue au programme qui supprime les balises d'HTML ***********"<<endl<<endl;
            cout<<"Comment voudriez-vous enregistrer le resultat ?"<<endl;
                    cout<<"\t 1\) Sous forme d'un fichier texte. "<<endl;
                    cout<<"\t 2\) Sur la console."<<endl<<endl;

                //V�rifier si le choix est different de 1 et 2
                do{
                    cout<<"Tapez votre choix \(1 ou 2 \) : ";
                    cin>>choix;

                    // V�rifier si le choix n'est pas un nombre
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(256,'\n');
                    }
                } while(choix!=1 && choix!=2);


            switch (choix) {
                case 1 :
                    //Enregistrer le resultat dans un fichier texte.

                    resultFile << result << endl;
                    cout << endl<<"Le traitement est fait avec succ�s. Le r�sultat est enregistrer dans le fichier resultat.txt."<<endl<<endl;
                    system("notepad.exe resultat.txt");


                    break;

                case 2 :
                    //Afficher les resultat sur la console.
                    cout<< result<<endl;
                    break;

            }

        }

    }
}
