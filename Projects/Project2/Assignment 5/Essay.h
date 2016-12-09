/* 
 * File:   Essay.h
 * Author: Bryan
 *
 * Created on December 1, 2016, 11:51 PM
 */

#ifndef ESSAY_H
#define	ESSAY_H

class GradedActivity
{
private:
    float score;
public:
    GradedActivity()
    {score = 0;}
    GradedActivity(float s)
    {score = s;}
    void setScore(float s)
    {score = s;}
    float getScore() const
    {return score;}
    char getLetterGrade() const;
};

class Essay : public GradedActivity
{
private:
    int grammar;
    int spelling;
    int length;
    int content;
public:
    Essay();
    Essay(int, int, int, int);
    int getTotal();
};

#endif	/* ESSAY_H */

