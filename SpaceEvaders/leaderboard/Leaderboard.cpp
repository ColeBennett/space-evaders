#include "Leaderboard.h"

LeaderBoard::LeaderBoard() {
	pHead = nullptr;
	fileStream.open("scores.txt");
	std::string line;
	float score = 0;
    int index = 0;
	while (!fileStream.eof()) {
		fileStream >> score;
		insertInOrder(score);
		index++;
	}
	fileStream.close();
}

LeaderBoard::~LeaderBoard() {
	while (pHead != nullptr) {
		LeaderboardEntry * pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
}

void LeaderBoard::insertInOrder(float score) {
	LeaderboardEntry* pCur = pHead;
	LeaderboardEntry* pPrev = nullptr;
	LeaderboardEntry* newNode = new LeaderboardEntry(score);
	if (newNode != nullptr) {
		if (pHead == nullptr) {
			pHead = newNode;
		} else if (newNode->getScore() > pCur->getScore()) {
			newNode->setNext(pCur);
			pHead = newNode;
		} else {
			while ((pCur != nullptr) && (newNode->getScore() < pCur->getScore())) {
				pPrev = pCur;
				pCur = pCur->getNext();
			}
            if (pPrev != nullptr) {
                pPrev->setNext(newNode);
                newNode->setNext(pCur);
            } else {
                newNode->setNext(pCur);
                pHead = pCur;
            }
		}
	}
}

void LeaderBoard::writeCSV() {
	LeaderboardEntry* pCur = pHead;
	fileStream.open("scores.txt");
	while (pCur->getNext() != nullptr) {
		fileStream << pCur->getScore() << std::endl;
		pCur = pCur->getNext();
	}
	fileStream << pCur->getScore();
	fileStream.close();
}

LeaderboardEntry *& LeaderBoard::getHeadPtr()
{
	return pHead;
}