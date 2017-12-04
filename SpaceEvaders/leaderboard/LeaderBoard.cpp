#include "LeaderBoard.h"

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
		LeaderBoardEntry * pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
}

void LeaderBoard::insertInOrder(float score) {
	LeaderBoardEntry* pCur = pHead;
	LeaderBoardEntry* pPrev = nullptr;
	LeaderBoardEntry* newNode = new LeaderBoardEntry(score);
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

void LeaderBoard::printLeaderBoard() {
	LeaderBoardEntry* pCur = pHead;
	while (pCur != nullptr) {
		std::cout << pCur->getScore() << std::endl;
		pCur = pCur->getNext();
	}
}

void LeaderBoard::writeCSV() {
	LeaderBoardEntry* pCur = pHead;
	fileStream.open("scores.txt");
	while (pCur->getNext() != nullptr) {
		fileStream << pCur->getScore() << std::endl;
		pCur = pCur->getNext();
	}
	fileStream << pCur->getScore();
	fileStream.close();
}

LeaderBoardEntry *& LeaderBoard::getHeadPtr()
{
	return pHead;
}