#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Person{
    int id;
    int speed;
    struct Person* next;
}Person;


Person updatePerson(int id, int speed){
    struct Person person = {id, speed, NULL};
    return person;
}


void addPerson(Person** start, Person* new) {

    //if the list is empty
    if (*start == NULL) {
        *start = new;
        new->next = new;
        return;
    }

    //find the last person
    struct Person *index = *start;
    for (; index->next != *start; index = index->next);

    //insert the new node
    new->next = index->next;
    index->next = new;
}


// Returns the winner
Person* play(Person* start) {

    //select player p
    struct Person *p = start;

    //play until one remains
    while (p->next != p) {

        //call n people duck
        struct Person *beforeSit = p;
        struct Person *sit = p->next;
        for (int i = 0; i < p->id; i++) {

            //if the loop reaches back to p, continue
            if (sit == p) {
                sit = sit->next;
                beforeSit = beforeSit->next;
                i--;
                continue;
            }

            //count the sitter as a duck and continue to the next person
            printf("%d duck %d\n", p->id, sit->id);
            sit = sit->next;
            beforeSit = beforeSit->next;
        }

        //fixing an edge case
        if (sit == p) {
            sit = sit->next;
            beforeSit = beforeSit->next;
        }

        //call the n+1 person goose
        printf("%d goose! %d\n", p->id, sit->id);

        //eliminate the slower player
        if (p->speed > sit->speed) {
            beforeSit->next = sit->next;
            free(sit);

        } else {

            //find the person right before p
            struct Person *beforeP = p->next;
            for (; beforeP->next != p; beforeP = beforeP->next);

            //fix the loop and remove p
            struct Person *temp = p;
            beforeP->next = p->next;
            p = sit;
            free(temp);
        }
    }

    printf("winner! %d\n", p->id);
    return p;
}


/*int main(){
    int p, s;

    // List of people
    Person* lop = NULL;

    // Read in participants
    while (scanf("%d %d", &p, &s) == 2){
        Person* np = (Person*)malloc(sizeof(Person));
        *np = updatePerson(p, s);
        addPerson(&lop, np);
    }

    Person* winner = play(lop);
    free(winner);
}*/