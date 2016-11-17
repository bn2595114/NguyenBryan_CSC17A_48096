/* 
 * File:   TestScore.h
 * Author: Bryan
 *
 * Created on November 16, 2016, 9:51 PM
 */

#ifndef TESTSCORE_H
#define	TESTSCORE_H

class TestScore
{
private:
    float test1;
    float test2;
    float test3;
    float avg;
public:
    float setAvg()
    {
        avg = (test1 + test2 + test3)/3;
    }
    TestScore(float one, float two, float three)
    {
        test1 = one; test2 = two; test3 = three;
        setAvg();
    }
    float getTest1() const {return test1;}
    float getTest2() const {return test2;}
    float getTest3() const {return test3;}
    float getAvg() const {return avg;}
};

#endif	/* TESTSCORE_H */

