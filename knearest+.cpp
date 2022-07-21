#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip> 
#define N 1000
#define K 30
using namespace std;
class  MoviePredictor
{
public:
    int Сomedy;
    int Drama;
    int Crime;
    int Horror;
    int Fantasy;
    int Thriller;
    int Musical;
    int Action;
    int Adventure;

public:
    void SetMarks();
    void ShowMarks();

};

void MoviePredictor::SetMarks()    
{
    Сomedy = rand() % 10 + 1;
    Drama = rand() % 10 + 1;
    Crime = rand() % 10 + 1;
    Horror = rand() % 10 + 1;
    Fantasy = rand() % 10 + 1;
    Thriller = rand() % 10 + 1;
    Musical = rand() % 10 + 1;
    Action = rand() % 10 + 1;
    Adventure = rand() % 10 + 1;
}


void MoviePredictor::ShowMarks()   
{
    cout << "Сomedy " << Сomedy << "  Drama " << Drama << "  Crime " << Crime << "  Horror " << Horror << "  Fantasy " << Fantasy << "  Thriller " << Thriller << "  Musical " << Musical << "  Action " << Action << "  Adventure " << Adventure;
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    MoviePredictor neighbours[N];
    for (int i = 0; i < N; i++)
        neighbours[i].SetMarks();
   /* for (int i = 0; i < N; i++)
    {
        cout << "Сосед номер : " << "\n";
        neighbours[i].ShowMarks();
    }*/

    MoviePredictor NoName;
    NoName.SetMarks();
    cout << "Новый объект: " << "\n";
    NoName.ShowMarks();
    double Length[N], Lengthtemp[N], temp = 0, temp2 = 0;
    double Nearest[K];
    int Nom[N], s = 1;

    for (int i = 0; i < N; i++) {
        Nom[i] = i;
    }

    for (int i = 0; i < N; i++) // вычисление расстояний 
    {
        Length[i] = sqrt(((NoName.Сomedy - neighbours[i].Сomedy) * (NoName.Сomedy - neighbours[i].Сomedy)) + ((NoName.Drama - neighbours[i].Drama) * (NoName.Drama - neighbours[i].Crime)) + ((NoName.Crime - neighbours[i].Crime) * (NoName.Crime - neighbours[i].Crime)) + ((NoName.Horror - neighbours[i].Horror) * (NoName.Horror - neighbours[i].Horror)) + ((NoName.Fantasy - neighbours[i].Fantasy) * (NoName.Fantasy - neighbours[i].Fantasy)) + ((NoName.Thriller - neighbours[i].Thriller) * (NoName.Thriller - neighbours[i].Thriller)) + ((NoName.Musical - neighbours[i].Musical) * (NoName.Musical - neighbours[i].Musical)) + ((NoName.Action - neighbours[i].Action) * (NoName.Action - neighbours[i].Action)) + ((NoName.Adventure - neighbours[i].Adventure) * (NoName.Adventure - neighbours[i].Adventure)));
    }
    for (int i = 0; i < N; i++) // вычисление расстояний 
    {
        Lengthtemp[i] = sqrt(((NoName.Сomedy - neighbours[i].Сomedy) * (NoName.Сomedy - neighbours[i].Сomedy)) + ((NoName.Drama - neighbours[i].Drama) * (NoName.Drama - neighbours[i].Crime)) + ((NoName.Crime - neighbours[i].Crime) * (NoName.Crime - neighbours[i].Crime)) + ((NoName.Horror - neighbours[i].Horror) * (NoName.Horror - neighbours[i].Horror)) + ((NoName.Fantasy - neighbours[i].Fantasy) * (NoName.Fantasy - neighbours[i].Fantasy)) + ((NoName.Thriller - neighbours[i].Thriller) * (NoName.Thriller - neighbours[i].Thriller)) + ((NoName.Musical - neighbours[i].Musical) * (NoName.Musical - neighbours[i].Musical)) + ((NoName.Action - neighbours[i].Action) * (NoName.Action - neighbours[i].Action)) + ((NoName.Adventure - neighbours[i].Adventure) * (NoName.Adventure - neighbours[i].Adventure)));
    }
    cout << "Массив до сортировки";
    for (int i = 0; i < N; i++)
        cout << fixed << setprecision(3) << " " << Length[i];

    cout << "\n\n\n\n";
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (Lengthtemp[j] < Lengthtemp[j - 1]) {
                temp = Lengthtemp[j - 1];
                temp2 = Nom[j - 1];
                Lengthtemp[j - 1] = Lengthtemp[j];
                Nom[j - 1] = Nom[j];
                Lengthtemp[j] = temp;
                Nom[j] = temp2;
            }
        }
    }
    cout << "Массив после сортировки";
    for (int i = 0; i < N; i++)
        cout << fixed << setprecision(3) << " " << Lengthtemp[i];
    cout << "\n\n\n\n";
    cout << "Индексы элементов после сортировки";
    for (int i = 0; i < N; i++)
        cout << " " << Nom[i];
    cout << "\n";

    for (int i = 0; i < K; i++) {
        Nearest[i] = Length[Nom[i]];
    }

    cout << "Ближайшие соседи ";
    for (int i = 0; i < K; i++)
        cout << " " << Nearest[i];

    double СomedyAvg[2] = { 0,0 };
    double DramaAvg[2] = { 0,0 };
    double CrimeAvg[2] = { 0,0 };
    double HorrorAvg[2] = { 0,0 };
    double FantasyAvg[2] = { 0,0 };
    double ThrillerAvg[2] = { 0,0 };
    double MusicalAvg[2] = { 0,0 };
    double ActionAvg[2] = { 0,0 };
    double AdventureAvg[2] = { 0,0 };

    for (int i = 0; i < K; i++) {
        СomedyAvg[0] += neighbours[Nom[i]].Сomedy;
        DramaAvg[0] += neighbours[Nom[i]].Drama;
        CrimeAvg[0] += neighbours[Nom[i]].Crime;
        HorrorAvg[0] += neighbours[Nom[i]].Horror;
        FantasyAvg[0] += neighbours[Nom[i]].Fantasy;
        ThrillerAvg[0] += neighbours[Nom[i]].Thriller;
        MusicalAvg[0] += neighbours[Nom[i]].Musical;
        ActionAvg[0] += neighbours[Nom[i]].Action;
        AdventureAvg[0] += neighbours[Nom[i]].Adventure;
    }
   

   // cout << "\nСредние значения " << СomedyAvg[0] << " " << DramaAvg[0] << " " << CrimeAvg[0] << " " << HorrorAvg[0] << " " << FantasyAvg[0] << " " << ThrillerAvg[0] << " " << MusicalAvg[0] << " " << ActionAvg[0] << " " << AdventureAvg[0];
    СomedyAvg[0] /= K;
    DramaAvg[0] /= K;
    CrimeAvg[0] /= K;
    HorrorAvg[0] /= K;
    FantasyAvg[0] /= K;
    ThrillerAvg[0] /= K;
    MusicalAvg[0] /= K;
    ActionAvg[0] /= K;
    AdventureAvg[0] /= K;
    cout << "\nСредние значения " << "Comedy " << СomedyAvg[0] << " " << "Drama " << DramaAvg[0] << " " << "Crime " << CrimeAvg[0] << " " << "Horror " << HorrorAvg[0] << " " << "Fantasy " << FantasyAvg[0] << " " << "Thriller " << ThrillerAvg[0] << " " << "Musical " << MusicalAvg[0] << " " << "Action " << ActionAvg[0] << " " << "Adventure " << AdventureAvg[0];
 
    cout << "\nВведите количество жанров вашего фильма (не более 9 и не менее 1) ";
    int koef, l;
    double avgchecker = 0.0;
    cin >> koef;
    cout << "\nВведите номера жанров в порядке убывания важности ";
    cout << "\n 1 Comedy \n 2 Drama \n 3 Crime \n 4 Horror \n 5 Fantasy \n 6 Thhriller \n 7 Musical \n 8 Action \n 9 Adventure\n";
    int value;
    double  weight = 0.9;
    for (l = 0; l < koef; l++)
    {
        weight += 0.1;
        avgchecker += weight;
    }
    avgchecker /= l;
    cout << "\n" << "avgchecker " << avgchecker << "\n";
    while (weight > 0.95) 
    {
        cin >> value;
        switch (value)
        {
        case 1: {СomedyAvg[1] = СomedyAvg[0] * weight; weight -= 0.1; break; }
        case 2: {DramaAvg[1] = DramaAvg[0] * weight; weight -= 0.1; break; }
        case 3: {CrimeAvg[1] = CrimeAvg[0] * weight; weight -= 0.1; break; }
        case 4: {HorrorAvg[1] = HorrorAvg[0] * weight; weight -= 0.1; break;}
        case 5: {FantasyAvg[1] = FantasyAvg[0] * weight; weight -= 0.1; break; }
        case 6: {ThrillerAvg[1] = ThrillerAvg[0] * weight; weight -= 0.1; break; }
        case 7: {MusicalAvg[1] = MusicalAvg[0] * weight; weight -= 0.1; break; }
        case 8: {ActionAvg[1] = ActionAvg[0] * weight; weight -= 0.1; break; }
        case 9: {AdventureAvg[1] = AdventureAvg[0] * weight; weight -= 0.1; break; }
        }
    }
    cout << "\n" << weight;
    cout << "\nСредние взвешанные значения " << "СomedyAvg " << СomedyAvg[1] << " " << "DramaAvg " << DramaAvg[1] << " " << "CrimeAvg " << CrimeAvg[1] << " " << "HorrorAvg" << HorrorAvg[1] << " " << "FantasyAvg " << FantasyAvg[1] << " " << "ThrillerAvg " << ThrillerAvg[1] << " " << "MusicalAvg" << MusicalAvg[1] << " " << "ActionAvg" << ActionAvg[1] << " " << "AdventureAvg" << AdventureAvg[1];
    double Mark;
    Mark = СomedyAvg[1] + DramaAvg[1] + CrimeAvg[1] + HorrorAvg[1] + FantasyAvg[1] + ThrillerAvg[1] + MusicalAvg[1] + ActionAvg[1] + AdventureAvg[1];
    Mark /= (koef* avgchecker);
    cout << "\nMark " << Mark;
   
}