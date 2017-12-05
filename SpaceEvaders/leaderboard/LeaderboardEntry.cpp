#include "LeaderboardEntry.h"

LeaderboardEntry::LeaderboardEntry(float newScore) {
	score = newScore;
	pNext = nullptr;
}

LeaderboardEntry::~LeaderboardEntry() {

}

float LeaderboardEntry::getScore() const {
	return score;
}

LeaderboardEntry *  LeaderboardEntry::getNext() const {
	return pNext;
}

void LeaderboardEntry::setScore(float newScore) {
	score = newScore;
}

void LeaderboardEntry::setNext(LeaderboardEntry * pNewNext) {
	pNext = pNewNext;
}