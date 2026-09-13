#ifndef AI_H
#define AI_H

#include "University.h"
#include <string>
#include <cmath> 

using namespace std;

class AI {
public:
    struct Prediction {
        double percent;
        string message;
        
    };

    static Prediction analyze(int userRank, University& u) {
        Prediction p;
        p.message = "";

       
        double diff = (double)u.rank - userRank;
        double score = 50.0;
        double oran = diff / (double)u.rank;
        score += (oran * 50.0);

        if (userRank > u.rank * 1.3) {
            score = 1; 
            p.message = "[Siralama farki cok yuksek.}] ";
        }

        if (score > 10) {
            if (u.lastYearRank > 0) {
                int trendDiff = u.lastYearRank - u.rank; 

                if (trendDiff > 2000) {
                    score += 5;
                    p.message += "[Trend: COK IYI]. ";
                }
                else if (trendDiff > 0) {
                    score += 2;
                    p.message += "[Trend: Yukseliste]. ";
                }
                else if (trendDiff == 0) {
                    p.message += "[Trend: Stabil]. ";
                }
                else {
                    score -= 5;
                    p.message += "[Trend: Dususte]. ";
                }
            }
            else {
                p.message += "[Yeni Bolum]. ";
            }
        }
       
        if (score > 30 && score < 70) {
            if (u.cityTier == 1) { 
                score -= 2; 
                p.message += "Buyuksehir rekabeti yuksek. ";
            }
            else if (u.cityTier == 2) { 
                score += 5; 
                p.message += "Sehir avantaji var. ";
            }
        }

        if (score > 99.0) score = 99.0;
        if (score < 1.0) score = 1.0;

        p.percent = score;

        string anaDurum = "";

        if (score >= 80)  anaDurum = "BANKO! ";
        
        else if (score >= 50)   anaDurum = "GUCLU ADAY. ";
       
        else if (score >= 30)   anaDurum = "Surpriz. ";
        
        else  anaDurum = "HAYAL . ";
       

        p.message  = anaDurum + p.message;
      
        return p;
    }
};

#endif