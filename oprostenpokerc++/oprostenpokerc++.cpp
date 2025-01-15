/**
*Solution to course project # 10
*Introduction to programming course
*Faculty of Mathematicsand Informatics of Sofia University
*Winter semester 2023 / 2024
*
*@author Borislav Yanev
*@idnumberг 9MI0600483* @compiler VC
* 
*<whole file for the game>
*
*/
#include <iostream>
#include <vector>

unsigned int simpleRandom(unsigned int seed) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff; // Линеен конгруентен генератор
    return seed;
}

int checkpoints(int valueofcard) {
    int points = 0;
    switch (valueofcard)
    {
    case 7:
        points = 7;
        break;
    case 8:
        points = 8;
        break;
    case 9:
        points = 9;
        break;
    case 10:
        points = 10;
        break;
    case 11:
        points = 10;
        break;
    case 12:
        points = 10;
        break;
    case 13:
        points = 10;
        break;
    case 14:
        points = 11;
        break;
    }

    return points;
}

int checkhand(int card1,int card2,int card3) {

    int handpoints = 0;

    int valueofcard1 = card1 / 10;
    int suitofcard1 = card1 % 10;
    int pointsofcard1 = checkpoints(valueofcard1);

    int valueofcard2 = card2 / 10;
    int suitofcard2 = card2 % 10;
    int pointsofcard2 = checkpoints(valueofcard2);

    int valueofcard3 = card3 / 10;
    int suitofcard3 = card3 % 10;
    int pointsofcard3 = checkpoints(valueofcard3);


    if (valueofcard1 == 7 && suitofcard1 == 3) {
    //Ако първата карта е седмица спатия
        if (valueofcard2 == valueofcard3) {
            handpoints = pointsofcard2 * 2 + 11;
        }
        else if (suitofcard2 == suitofcard3) {
            handpoints = pointsofcard2 + pointsofcard3 + 11;
        }
        else if (valueofcard2 > valueofcard3) {
            handpoints = pointsofcard2 + 11;
        }
        else {
            handpoints = pointsofcard3 + 11;
        }
    }
    else if (valueofcard2 == 7 && suitofcard2 == 3) {
    //Ако втората карта е седмица спатия
        if (valueofcard1 == valueofcard3) {
            handpoints = pointsofcard1 * 2 + 11;
        }
        else if (suitofcard1 == suitofcard3) {
            handpoints = pointsofcard1 + pointsofcard3 + 11;
        }
        else if (valueofcard1 > valueofcard3) {
            handpoints = pointsofcard1 + 11;
        }
        else {
            handpoints = pointsofcard3 + 11;
        }

    }
    else if (valueofcard3 == 7 && suitofcard3 == 3) {
        //Ако третата карта е седмица спатия
        if (valueofcard1 == valueofcard2) {
            handpoints = pointsofcard1 * 2 + 11;
        }
        else if (suitofcard1 == suitofcard2) {
            handpoints = pointsofcard1 + pointsofcard2 + 11;
        }
        else if (valueofcard1 > valueofcard2) {
            handpoints = pointsofcard1 + 11;
        }
        else {
            handpoints = pointsofcard2 + 11;
        }
    }
    else if (valueofcard1 == valueofcard2 && valueofcard2 == valueofcard3) {
        //Проверка за ако са еднакви и 3те карти
        if (valueofcard1 == 7) {
            handpoints = 34;
        }
        else {
            handpoints = pointsofcard1 * 3;
        }
    }
    else if (suitofcard1 == suitofcard2 && suitofcard2 == suitofcard3) {
        //Проверка ако боята и на трите е еднаква
        handpoints = pointsofcard1 + pointsofcard2 + pointsofcard3;
    }
    else if (valueofcard1 == valueofcard2 || valueofcard1 == valueofcard3){
        //Ако първата и някоя карта съвпадат и са асак или 7
        if (valueofcard1 == 7) {
            handpoints = 23;
        }
        else if (valueofcard1 == 14) {
            handpoints = pointsofcard1 * 2;
        }
        else { 
            if (suitofcard1 == suitofcard2) {
                //3 проверки за ако две са от един и същ цвят
                handpoints = pointsofcard1 + pointsofcard2;
            }
            else if (suitofcard1 == suitofcard3) {
                handpoints = pointsofcard1 + pointsofcard3;
            }
            else if (suitofcard2 == suitofcard3) {
                handpoints = pointsofcard2 + pointsofcard3;
            }
            else {
                if (valueofcard1 >= valueofcard2 && valueofcard1 >= valueofcard3) {
                    handpoints = pointsofcard1;
                }
                else if (valueofcard2 >= valueofcard1 && valueofcard2 >= valueofcard3) {
                    handpoints = pointsofcard2;
                }
                else {
                    handpoints = pointsofcard3;
                }
            }
        }
    }
    else if (valueofcard2 == valueofcard3) {
        //Ако втората и третата карта съвпадат и са асак или 7
        if (valueofcard2 == 7) {
            handpoints = 23;
        }
        else if (valueofcard2 == 14) {
            handpoints = pointsofcard2 * 2;
        }
        else { 
            if (suitofcard1 == suitofcard2) {
                //3 проверки за ако две са от един и същ цвят
                handpoints = pointsofcard1 + pointsofcard2;
            }
            else if (suitofcard1 == suitofcard3) {
                handpoints = pointsofcard1 + pointsofcard3;
            }
            else if (suitofcard2 == suitofcard3) {
                handpoints = pointsofcard2 + pointsofcard3;
            }
            else {
                if (valueofcard1 >= valueofcard2 && valueofcard1 >= valueofcard3) {
                    handpoints = pointsofcard1;
                }
                else if (valueofcard2 >= valueofcard1 && valueofcard2 >= valueofcard3) {
                    handpoints = pointsofcard2;
                }
                else {
                    handpoints = pointsofcard3;
                }
            }
        }
    }else if (suitofcard1 == suitofcard2) {
        //3 проверки за ако две са от един и същ цвят
        handpoints = pointsofcard1 + pointsofcard2;
    }
    else if (suitofcard1 == suitofcard3) {
    handpoints = pointsofcard1 + pointsofcard3;
    }
    else if (suitofcard2 == suitofcard3) {
    handpoints = pointsofcard2 + pointsofcard3;
    }
    else {
    if (valueofcard1 >= valueofcard2 && valueofcard1 >= valueofcard3) {
        handpoints = pointsofcard1;
    }
    else if (valueofcard2 >= valueofcard1 && valueofcard2 >= valueofcard3) {
        handpoints = pointsofcard2;
    }
    else {
        handpoints = pointsofcard3;
    }
    }
    
    
    return handpoints;
    
}

char checkpaint(int suitofcard) {
    char paint = 'S';
    switch (suitofcard)
    {
    case 0:
        paint = 'S';
        break;
    case 1:
        paint = 'D';
        break;
    case 2:
        paint = 'H';
        break;
    case 3:
        paint = 'C';
        break;
    }
    return paint;
}

char checkthecard(int valueofcard) {

    char letter = 'J';
    switch (valueofcard)
    {
    case 11:
        letter = 'J';
        break;
    case 12:
        letter = 'Q';
        break;
    case 13:
        letter = 'K';
        break;
    case 14:
        letter = 'A';
        break;
    }
    return letter;

}

void printcards(int card1, int card2, int card3){

    int valueofcard1 = card1 / 10;
    int suitofcard1 = card1 % 10;
    char paintofcard1 = checkpaint(suitofcard1);
    if (valueofcard1 > 10) {
        char letterofcard1 = checkthecard(valueofcard1);
        std::cout << letterofcard1 << paintofcard1 << " ";
    }
    else {
        std::cout << valueofcard1 << paintofcard1 << " ";
    }

    int valueofcard2 = card2 / 10;
    int suitofcard2 = card2 % 10;
    char paintofcard2 = checkpaint(suitofcard2);
    if (valueofcard2 > 10) {
        char letterofcard2 = checkthecard(valueofcard2);
        std::cout << letterofcard2 << paintofcard2 << " ";
    }
    else {
        std::cout << valueofcard2 << paintofcard2 << " ";
    }

    int valueofcard3 = card3 / 10;
    int suitofcard3 = card3 % 10;
    char paintofcard3 = checkpaint(suitofcard3);
    if (valueofcard3 > 10) {
        char letterofcard3 = checkthecard(valueofcard3);
        std::cout << letterofcard3 << paintofcard3 << "   ";
    }
    else {
        std::cout << valueofcard3 << paintofcard3 << "   ";
    }


}

bool checktheraisesize(int raisedchips,int numplayers,int igrachi[9][8]) {

    bool checker = true;

    for (int i = 0; i < numplayers;i++) {
        if (raisedchips > igrachi[i][0]&& igrachi[i][5] == 1) {
            checker = false;
        }

    }

    return checker;
}

void checkthewinner(int numplayers, int potmoney, int igrachi[9][8],std::vector<int> deck, unsigned int seed) {

    std::vector<int> pointscombinations;
    for (int i = 0; i < numplayers; i++)
    {
        if (igrachi[i][5] == 1) {
            pointscombinations.push_back(igrachi[i][4]);
        }
    }
    int maxcombination = pointscombinations[0];//Намираме най голямата комбинация
    for (int i = 0; i < pointscombinations.size(); i++)
    {
        if (pointscombinations[i] > maxcombination) {
            maxcombination = pointscombinations[i];
        }
    }
    int pointssize = pointscombinations.size();
    for (int i = 0; i < pointssize; i++)
    {
        pointscombinations.pop_back();
    }
    std::vector<int> listwithplayerswithmaxhand;
    for (int i = 0; i < numplayers; i++)
    {
        if (igrachi[i][5] == 1 && igrachi[i][4] == maxcombination) {
            listwithplayerswithmaxhand.push_back(i);
            igrachi[i][5] = 0;
        }
    }

    if (listwithplayerswithmaxhand.size() == 1) {
    
        int indexofwinningplayer = listwithplayerswithmaxhand[0];
        igrachi[indexofwinningplayer][0] += potmoney;
        std::cout << "The round has ended , congrats to Player" << indexofwinningplayer+1 << std::endl;

    }
    else if (listwithplayerswithmaxhand.size() > 1) {

        bool thereisonlyoneplayerleft = false;
        int tax = 0;

        do {
            tax = potmoney / 2;
            if (tax % 10 == 5) {
                tax += 5;
            }

            for (int i = 0; i < numplayers; i++)
            {
                if (igrachi[i][5] == 1) {
                    char answer = 's';
                    do {
                        if (igrachi[i][0] >= tax) {
                            std::cout << "Player" << i + 1 << ", do you want to join the TIE? You have to pay " << tax << " (y/n) : ";
                            std::cin >> answer;
                            if (answer == 'y') {
                                igrachi[i][5] = 1;
                                igrachi[i][0] -= tax;
                                potmoney += tax;
                                if (igrachi[i][0] == 0) {
                                    igrachi[i][0] += 50;
                                }

                            }
                            else if (answer == 'n') {
                                igrachi[i][5] = 0;
                            }

                        }
                        else {
                            std::cout << "Sorry player " << i + 1 << " you don't have the money to continue ! ";
                        }

                    } while (answer != 'y' && answer != 'n');

                }

            }
            int size = listwithplayerswithmaxhand.size();
            for (int i = 0; i < size; i++) {
                int playerindex = listwithplayerswithmaxhand[i];
                igrachi[playerindex][5] = 1;   
                if (igrachi[playerindex][0] == 0) {

                    igrachi[playerindex][0] += 50;

                }

            }
            for (int i = 0; i < size; i++) {
                listwithplayerswithmaxhand.pop_back();
                
            }

            for (int i = 0; i < numplayers; i++)//Занулявам на всички парите които са дали до момента в пота
            {
                igrachi[i][6] = 0;
                igrachi[i][7] = 0;
            }

            //Вече имам всички играчи които ще участват в новото раздване

            for (size_t i = 0; i < deck.size(); ++i) {//Ново разбъркване 
                seed = simpleRandom(seed);
                unsigned int randomIndex = seed % deck.size();
                std::swap(deck[i], deck[randomIndex]);
            }

            int cardcounter = 0;
            for (int i = 0; i < numplayers; i++) {//Раздаване на чипове
                for (int j = 1; j < 4; j++) {//Раздаване на карти
                    if (igrachi[i][5] == 1) {
                        igrachi[i][j] = deck[cardcounter];
                        cardcounter++;
                    }
                }
                int card1 = igrachi[i][1];
                int card2 = igrachi[i][2];
                int card3 = igrachi[i][3];
                int handstrenght = checkhand(card1, card2, card3);
                igrachi[i][4] = handstrenght;//сила на комбинацията
            }


            int lastraise = 0;

            for (int j = 0; j < numplayers; j++) {//Първото раздаване от играта
                if (igrachi[j][5] == 1) {

                    for (int i = 0; i < numplayers; i++)
                    {
                        std::cout << "Player" << i + 1 << ": " << igrachi[i][0] << " ";
                    }
                    std::cout << std::endl << std::endl;

                    std::cout << "Pot: " << potmoney << std::endl << std::endl;


                    //частта на всеки играч
                

                        std::cout << "You have given: " << igrachi[j][6] << std::endl;
                        
                        std::cout << "Last raise is: " << lastraise << std::endl << std::endl;

                        int card1 = igrachi[j][1];
                        int card2 = igrachi[j][2];
                        int card3 = igrachi[j][3];
                        printcards(card1, card2, card3);
                        std::cout << igrachi[j][4] << std::endl;
                        char action = 's';
                        if (lastraise == 0) {

                            std::cout << "Player" << j + 1 << " raise,call or fold ?(r/f): ";
                            std::cin >> action;

                            switch (action)
                            {
                            case 'f':
                                igrachi[j][5] = 0;
                                break;
                            case 'r':
                                std::cout << std::endl;
                                int raisedchips;
                                bool correctraise = true;
                                do {
                                    std::cout << "How many chips do you want to raise ? ";

                                    std::cin >> raisedchips;
                                    if ((raisedchips >= lastraise + 10) && checktheraisesize(raisedchips, numplayers, igrachi) && raisedchips % 10 == 0) {

                                        correctraise = false;

                                    }
                                } while (correctraise);

                                lastraise = raisedchips;
                                igrachi[j][0] -= lastraise;
                                igrachi[j][6] += lastraise;
                                potmoney += lastraise;
                                for (int k = 0; k < numplayers; k++) //Правя всички стойности за рейзване на 0                      
                                {
                                    igrachi[k][7] = 0;
                                }
                                igrachi[j][7] = 1;

                                break;
                            }

                        }
                        else{
                        std::cout << "Player" << j + 1 << " raise,call or fold ?(r/c/f): ";
                        std::cin >> action;

                        switch (action)
                        {

                        case 'f':
                            igrachi[j][5] = 0;
                            break;

                        case 'c':
                            if (lastraise != 0) {
                                igrachi[j][0] -= lastraise;
                                igrachi[j][6] += lastraise;
                                potmoney += lastraise;
                            }
                            break;
                        case 'r':
                            std::cout << std::endl;
                            int raisedchips;
                            bool correctraise = true;
                            do {
                                std::cout << "How many chips do you want to raise ? ";

                                std::cin >> raisedchips;
                                if ((raisedchips >= lastraise + 10) && checktheraisesize(raisedchips, numplayers, igrachi) && raisedchips % 10 == 0) {

                                    correctraise = false;

                                }
                            } while (correctraise);

                            lastraise = raisedchips;
                            igrachi[j][0] -= lastraise;
                            igrachi[j][6] += lastraise;
                            potmoney += lastraise;
                            for (int k = 0; k < numplayers; k++) //Правя всички стойности за рейзване на 0                      
                            {
                                igrachi[k][7] = 0;
                            }
                            igrachi[j][7] = 1;

                            break;
                        }
                    }
                }
                std::cout << std::endl;

            }

            bool someoneelsehasraised = false;

            for (int i = 0; i < numplayers; i++)//Останалите завъртвания
            {

                if (igrachi[i][5] == 1) {//Проверяваме дали участва

                    if (igrachi[i][7] == 1) {//Това проверява дали този играч на който сме е последния рейзнал,ако е спираме цикъла
                        std::cout << "The betting is closed !" << std::endl;
                        break;
                    }
                    else {

                        for (int i = 0; i < numplayers; i++)
                        {
                            std::cout << "Player" << i + 1 << ": " << igrachi[i][0] << " ";
                        }
                        std::cout << std::endl << std::endl;

                        std::cout << "Pot: " << potmoney << std::endl << std::endl;


                        //частта на всеки играч

                        std::cout << "You have given: " << igrachi[i][6] << std::endl;

                        std::cout << "Last raise is: " << lastraise << std::endl << std::endl;

                        int card1 = igrachi[i][1];
                        int card2 = igrachi[i][2];
                        int card3 = igrachi[i][3];
                        printcards(card1, card2, card3);
                        std::cout << igrachi[i][4] << std::endl;
                        char action = 's';
                        std::cout << "Player" << i + 1 << " raise,call or fold ?(r/c/f): ";
                        std::cin >> action;

                        switch (action)
                        {

                        case 'f':
                            igrachi[i][5] = 0;
                            break;

                        case 'c':
                            if (lastraise != 0) {
                                igrachi[i][0] -= (lastraise - igrachi[i][6]);
                                potmoney += (lastraise - igrachi[i][6]);
                                igrachi[i][6] += (lastraise - igrachi[i][6]);

                            }
                            break;
                        case 'r':
                            std::cout << std::endl;
                            int raisedchips;
                            bool correctraise = true;
                            do {
                                std::cout << "How many chips do you want to raise ? ";

                                std::cin >> raisedchips;
                                if ((raisedchips >= lastraise + 10) && checktheraisesize(raisedchips, numplayers, igrachi) && raisedchips % 10 == 0) {

                                    correctraise = false;

                                }
                            } while (correctraise);

                            lastraise = raisedchips;
                            igrachi[i][0] -= (lastraise - igrachi[i][6]);
                            potmoney += (lastraise - igrachi[i][6]);
                            igrachi[i][6] += (lastraise - igrachi[i][6]);


                            for (int k = 0; k < numplayers; k++) //Правя всички стойности за рейзване на 0                      
                            {
                                igrachi[k][7] = 0;
                            }
                            igrachi[i][7] = 1;//И увеличавам този който е рейзнал към момента
                            someoneelsehasraised = true;
                            break;
                        }

                    }

                    std::cout << std::endl;

                }

                if (someoneelsehasraised && i == numplayers - 1) {

                    someoneelsehasraised = false;
                    i = -1;
                }

            }//Край на завъртването бетването свърши

            for (int i = 0; i < numplayers; i++)
            {
                if (igrachi[i][5] == 1) {
                    pointscombinations.push_back(igrachi[i][4]);
                }
            }
            int maxcombination = pointscombinations[0];//Намираме най голямата комбинация
            for (int i = 0; i < pointscombinations.size(); i++)
            {
                if (pointscombinations[i] > maxcombination) {
                    maxcombination = pointscombinations[i];
                }
            }
            int pointssize = pointscombinations.size();
            for (int i = 0; i < pointssize; i++)
            {
                pointscombinations.pop_back();
            }
            
            for (int i = 0; i < numplayers; i++)
            {
                if (igrachi[i][5] == 1 && igrachi[i][4] == maxcombination) {
                    listwithplayerswithmaxhand.push_back(i);
                    igrachi[i][5] = 0;
                }
            }

            for (int i = 0; i < numplayers; i++)//Занулявам на всички парите които са дали до момента в пота
            {
                igrachi[i][6] = 0;
                igrachi[i][7] = 0;
            }

            if (listwithplayerswithmaxhand.size() == 1) {

                int indexofwinningplayer = listwithplayerswithmaxhand[0];
                igrachi[indexofwinningplayer][0] += potmoney;
                std::cout << "The round has ended , congrats to Player" << indexofwinningplayer + 1 << std::endl<<std::endl;
                thereisonlyoneplayerleft = true;
            }

        } while (!thereisonlyoneplayerleft);


    }





}

void playaroundofpoker(int numberofplayers,int spisuksigrachi[9][8]) {

    std::vector<int> deck;

    for (int suit = 0; suit < 4; ++suit) { // 4 цвята
        for (int value = 7; value <= 14; ++value) { // Стойности от 7 до 14
            deck.push_back(value * 10 + suit); // Уникален код за всяка карта
        }
    }

    unsigned int seed;
    std::cout << "Enter the seed for the shuffleing: ";
    std::cin >> seed;

    // Разбъркване на тестето
    for (size_t i = 0; i < deck.size(); ++i) {
        seed = simpleRandom(seed);
        unsigned int randomIndex = seed % deck.size();
        std::swap(deck[i], deck[randomIndex]);
    }

    int cardcounter = 0;
    for (int i = 0; i < numberofplayers; i++) {
        if (spisuksigrachi[i][0] >= 10) {
            for (int j = 1; j < 4; j++) {//Раздаване на карти
                spisuksigrachi[i][j] = deck[cardcounter];
                cardcounter++;
            }
            int card1 = spisuksigrachi[i][1];
            int card2 = spisuksigrachi[i][2];
            int card3 = spisuksigrachi[i][3];
            int handstrenght = checkhand(card1, card2, card3);
            spisuksigrachi[i][4] = handstrenght;//сила на комбинацията 
            spisuksigrachi[i][5] = 1;//1ако участват 0 ако не
            spisuksigrachi[i][6] = 0;//колко пари са дали в пота
            spisuksigrachi[i][7] = 0;//ще е 1 на този който последно е raisnal
        }
        else {
            spisuksigrachi[i][5] = 0;
        }
    }

    //Рунда започва

    int lastraise = 0;
    int potmoney = 0;

    for (int i = 0; i < numberofplayers; i++)
    {
        if (spisuksigrachi[i][0] >= 10) {
            spisuksigrachi[i][0] -= 10;
            potmoney += 10;
        }
    }

    for (int j = 0; j < numberofplayers; j++) {//Първото раздаване от играта

        for (int i = 0; i < numberofplayers; i++)
        {
            std::cout << "Player" << i + 1 << ": " << spisuksigrachi[i][0] << " ";
        }
        std::cout << std::endl << std::endl;

        std::cout << "Pot: " << potmoney << std::endl << std::endl;
        //Проверка ако има играч останал с 0 чипа
        bool checkifthereisanyoneiwith0 = false;
        for (int i = 0; i < numberofplayers; i++)
        {
            if (spisuksigrachi[i][5] == 1 && spisuksigrachi[i][0] == 0) {
                checkifthereisanyoneiwith0 = true;
            }
        }
        if(checkifthereisanyoneiwith0){

            for (int i = 0; i < numberofplayers; i++)
            {
                if (spisuksigrachi[i][5] == 1) {
                    int card1 = spisuksigrachi[i][1];
                    int card2 = spisuksigrachi[i][2];
                    int card3 = spisuksigrachi[i][3];
                    std::cout << "Player" << i+1 << "cards are : ";
                    printcards(card1, card2, card3);
                    std::cout << spisuksigrachi[i][4] << std::endl << std::endl;
                }
            }

        std::cout << "Sorry guys the betting is over because there is a player with 0 chips.";
        checkthewinner(numberofplayers, potmoney, spisuksigrachi, deck, seed);
        
        }

        //частта на всеки играч
        if (spisuksigrachi[j][5] == 1) {
            std::cout << "You have given: " << spisuksigrachi[j][6] << std::endl;
            if (j == 0) {
                std::cout << "Last raise is: " << 0 << std::endl << std::endl;
                lastraise = 0;
            }
            else {
                std::cout << "Last raise is: " << spisuksigrachi[j - 1][6] << std::endl << std::endl;

            }
            int card1 = spisuksigrachi[j][1];
            int card2 = spisuksigrachi[j][2];
            int card3 = spisuksigrachi[j][3];
            printcards(card1, card2, card3);
            std::cout << spisuksigrachi[j][4] << std::endl;
            char action = 's';
            if (lastraise == 0) {

                std::cout << "Player" << j + 1 << " raise,call or fold ?(r/f): ";
                std::cin >> action;

                switch (action)
                {
                case 'f':
                    spisuksigrachi[j][5] = 0;
                    break;
                case 'r':
                    std::cout << std::endl;
                    int raisedchips;
                    bool correctraise = true;
                    do {
                        std::cout << "How many chips do you want to raise ? ";

                        std::cin >> raisedchips;
                        if ((raisedchips >= lastraise + 10) && checktheraisesize(raisedchips, numberofplayers, spisuksigrachi) && raisedchips % 10 == 0) {

                            correctraise = false;

                        }
                    } while (correctraise);

                    lastraise = raisedchips;
                    spisuksigrachi[j][0] -= lastraise;
                    spisuksigrachi[j][6] += lastraise;
                    potmoney += lastraise;
                    for (int k = 0; k < numberofplayers; k++) //Правя всички стойности за рейзване на 0                      
                    {
                        spisuksigrachi[k][7] = 0;
                    }
                    spisuksigrachi[j][7] = 1;

                    break;
                }

            }
            else{
                std::cout << "Player" << j + 1 << " raise,call or fold ?(r/c/f): ";
                std::cin >> action;

                switch (action)
                {

                case 'f':
                    spisuksigrachi[j][5] = 0;
                    break;

                case 'c':
                    if (lastraise != 0) {
                        spisuksigrachi[j][0] -= lastraise;
                        spisuksigrachi[j][6] += lastraise;
                        potmoney += lastraise;
                    }
                    break;
                case 'r':
                    std::cout << std::endl;
                    int raisedchips;
                    bool correctraise = true;
                    do {
                        std::cout << "How many chips do you want to raise ? ";

                        std::cin >> raisedchips;
                        if ((raisedchips >= lastraise + 10) && checktheraisesize(raisedchips, numberofplayers, spisuksigrachi) && raisedchips % 10 == 0) {

                            correctraise = false;

                        }
                    } while (correctraise);

                    lastraise = raisedchips;
                    spisuksigrachi[j][0] -= lastraise;
                    spisuksigrachi[j][6] += lastraise;
                    potmoney += lastraise;
                    for (int k = 0; k < numberofplayers; k++) //Правя всички стойности за рейзване на 0                      
                    {
                        spisuksigrachi[k][7] = 0;
                    }
                    spisuksigrachi[j][7] = 1;

                    break;
                }
            }
            std::cout << std::endl;
        }
    }

    bool someoneelsehasraised = false;

    for (int i = 0; i < numberofplayers; i++)//Останалите завъртвания
    {

        if (spisuksigrachi[i][5] == 1) {//Проверяваме дали участва

            if (spisuksigrachi[i][7] == 1) {//Това проверява дали този играч на който сме е последния рейзнал,ако е спираме цикъла
                std::cout << "The betting is closed !" << std::endl << std::endl;
                break;
            }
            else {

                for (int i = 0; i < numberofplayers; i++)
                {
                    std::cout << "Player" << i + 1 << ": " << spisuksigrachi[i][0] << " ";
                }
                std::cout << std::endl << std::endl;

                std::cout << "Pot: " << potmoney << std::endl << std::endl;


                //частта на всеки играч

                std::cout << "You have given: " << spisuksigrachi[i][6] << std::endl;

                std::cout << "Last raise is: " << lastraise << std::endl << std::endl;

                int card1 = spisuksigrachi[i][1];
                int card2 = spisuksigrachi[i][2];
                int card3 = spisuksigrachi[i][3];
                printcards(card1, card2, card3);
                std::cout << spisuksigrachi[i][4] << std::endl;
                char action = 's';
                std::cout << "Player" << i + 1 << " raise,call or fold ?(r/c/f): ";
                std::cin >> action;

                switch (action)
                {

                case 'f':
                    spisuksigrachi[i][5] = 0;
                    break;

                case 'c':
                    if (lastraise != 0) {
                        spisuksigrachi[i][0] -= (lastraise - spisuksigrachi[i][6]);
                        potmoney += (lastraise - spisuksigrachi[i][6]);
                        spisuksigrachi[i][6] += (lastraise - spisuksigrachi[i][6]);

                    }
                    break;
                case 'r':
                    std::cout << std::endl;
                    int raisedchips;
                    bool correctraise = true;
                    do {
                        std::cout << "How many chips do you want to raise ? ";

                        std::cin >> raisedchips;
                        if ((raisedchips >= lastraise + 10) && checktheraisesize(raisedchips, numberofplayers, spisuksigrachi) && raisedchips % 10 == 0) {

                            correctraise = false;

                        }
                    } while (correctraise);

                    lastraise = raisedchips;
                    spisuksigrachi[i][0] -= (lastraise - spisuksigrachi[i][6]);
                    potmoney += (lastraise - spisuksigrachi[i][6]);
                    spisuksigrachi[i][6] += (lastraise - spisuksigrachi[i][6]);


                    for (int k = 0; k < numberofplayers; k++) //Правя всички стойности за рейзване на 0                      
                    {
                        spisuksigrachi[k][7] = 0;
                    }
                    spisuksigrachi[i][7] = 1;//И увеличавам този който е рейзнал към момента
                    someoneelsehasraised = true;
                    break;
                }

            }

            std::cout << std::endl;

        }

        if (someoneelsehasraised && i == numberofplayers - 1) {

            someoneelsehasraised = false;
            i = -1;
        }


    }

    checkthewinner(numberofplayers, potmoney, spisuksigrachi,deck,seed);

}

void startanewgame(int numberofplayers) {

    //std::vector<int> deck;
    //for (int suit = 0; suit < 4; ++suit) { // 4 цвята
    //    for (int value = 7; value <= 14; ++value) { // Стойности от 7 до 14
    //        deck.push_back(value * 10 + suit); // Уникален код за всяка карта
    //    }
    //}
    //unsigned int seed = 2222222;
    //// Разбъркване на тестето
    //for (size_t i = 0; i < deck.size(); ++i) {
    //    seed = simpleRandom(seed);
    //    unsigned int randomIndex = seed % deck.size();
    //    std::swap(deck[i], deck[randomIndex]);
    //}

    // Показване на разбърканото тесте
    //std::cout << "Shuffled deck:\n";
    //for (int card : deck) {
    //    int value = card / 10; // Стойността на картата
    //    int suit = card % 10;  // Цветът на картата
    //    std::string suitName;
    //    switch (suit) {
    //    case 0: suitName = "spades"; break;
    //    case 1: suitName = "diamonds"; break;
    //    case 2: suitName = "hearts"; break;
    //    case 3: suitName = "clubs"; break;
    //    }
    //    std::cout << value << " of " << suitName << "\n";
    //}
    
    int spisuksigrachi[9][8];
    int cardcounter = 0;

    for (int i = 0; i < numberofplayers;i++) {//Раздаване на чипове
        spisuksigrachi[i][0] = 1000;
    }
    
    //for (int i = 0; i < numberofplayers; i++) {//Показване на всички играчи с картите им да видя дали работи
    //    std::cout << spisuksigrachi[i][0]<< "  ";
    //    for (int j = 1; j < 5; j++) {
    //        std::cout << spisuksigrachi[i][j] << " ";       
    //    }
    //    std::cout << std::endl;
    //}

    playaroundofpoker(numberofplayers,spisuksigrachi);

    char action = 's';
    do {
       
            std::cout << "Do you want to play another round ? (y/n) : ";
            std::cin >> action;
            if (action == 'y') {
                playaroundofpoker(numberofplayers, spisuksigrachi);

            }
            else if (action == 'n') {
                
            }

    } while (action != 'n');
    std::cout << "Thank you for playing !"<< std::endl << std::endl;
    std::cout << "The results are saved in the file !";
    
}

int main() {
    int countplayers;
    do {
        std::cout << "How many players are going to play (2-9)? ";
        std::cin >> countplayers;

        if (countplayers < 2 || countplayers > 9) {
            std::cout << "Invalid number of players. Please enter a number between 2 and 9.\n";
        }
    } while (countplayers < 2 || countplayers > 9);
    startanewgame(countplayers);


}