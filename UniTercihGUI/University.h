
#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>

struct University {
    int id;
    std::string name;
    std::string department;
    double baseScore;
    int rank;
    int quota;
    int lastYearRank;
    int cityTier;

    // Boþ Kurucu (Gerekli)
    University() : id(0), baseScore(0.0), rank(0), quota(0), lastYearRank(0), cityTier(0) {}

    // Dolu Kurucu
    University(int _id, 
        std::string _n,
        std::string _d,
        double _s,
        int _r,
        int _q, 
        int _oldR,
        int _city)
    {


        id = _id;
        name = _n;
        department = _d;
        baseScore = _s;
        rank = _r;
        quota = _q;
        lastYearRank = _oldR;
        cityTier = _city;
    }
};

#endif
