/*
    KaibaCorp
    Bearden, Reese (TTh 6:30)
    Blood, William (TTh 6:30)
    Diep, Vince (TTh 2:20)
    Huynh, Andy (TTh 6:30)
    Nguyen, Andrew (MW 11:10)

    May 05, 2020

    CS A250
    Project 1 - Part B
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

// Default constructor
CandidateList::CandidateList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

// addCandidate
void CandidateList::addCandidate(const CandidateType& candidate) 
{
	Node* temp = new Node(candidate, nullptr);

	if (count == 0)
	{
		last = temp;
		first = temp;
	}
	else if (count > 0)
	{
		last->setLink(temp);
		last = last->getLink();
	}

	temp = nullptr;
	++count;
}

// getWinner
int CandidateList::getWinner() const 
{
	if (count == 0)
	{
		cerr << "=> List is empty.";
		return 0;
	}
	else
	{
		Node* temp = first;
		int top = 0;
		int idStore = 0;

		while (temp != last)
		{
			if (temp->getCandidate().getTotalVotes() > top)
			{
				top = temp->getCandidate().getTotalVotes();
				idStore = temp->getCandidate().getID();
			}
			temp = temp->getLink();
		}

		temp = nullptr;
		return idStore;
	}
}

// isEmpty
bool CandidateList::isEmpty() const 
{
	return (count == 0);
}

// searchCandidate
bool CandidateList::searchCandidate(int id) const 
{
	Node* temp = nullptr;
	return searchCandidate(id, temp);
}

bool CandidateList::searchCandidate(int id, Node*& ptr) const 
{
	Node* temp = first;
	bool found = false;
	while (temp != nullptr && !found)
	{
		if (temp->getCandidate().getID() == id)
		{
			ptr = temp;
			found = true;
			return found;
		}
		temp = temp->getLink();
	}

	if (!found)
	{
		cerr << "    => ID not in the list." << endl;
	}
	return found;
}

// printCandidateName
void CandidateList::printCandidateName(int id) const 
{
	Node* temp = nullptr;
	if (searchCandidate(id, temp))
	{
		temp->getCandidate().printName();
	}
}

// printAllCandidates
void CandidateList::printAllCandidates() const 
{
	Node* temp = first;
	while (temp != nullptr)
	{
		temp->getCandidate().printCandidateInfo();
		cout << endl;
		temp = temp->getLink();
	}
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int id, int index) const 
{
	Node* temp = nullptr;
	if (searchCandidate(id, temp))
	{
		cout << "    *" << right << setw(3) 
			<< temp->getCandidate().getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int id) const 
{
	Node* temp = nullptr;
	if (searchCandidate(id, temp))
	{
		cout << "    => Total votes: "
			<< temp->getCandidate().getTotalVotes() << endl;
	}
}

// printFinalResults
void CandidateList::printFinalResults() const 
{
	Node* temp = first;
	
	cout << "************ FINAL RESULTS ************" << endl << endl;

	cout << left << setw(15) << "LAST" << left << setw(10) << "FIRST"
		<< right << setw(5) << "TOTAL" << right << setw(7) << "POS" << endl;

	cout << left << setw(15) << "NAME" << left << setw(10) << "NAME"
		<< right << setw(5) << "VOTES" << right << setw(7) << "#" << endl;

	cout << "_______________________________________" << endl << endl;


	//int max = temp->getCandidate().getTotalVotes();
	//int maxId[31];	// All possible candidates SORTED
	//
	//for (int i = 0; temp->getLink() != nullptr;)
	//{
	//	if (max > temp->getLink()->getCandidate().getTotalVotes())
	//	{
	//		max = temp->getCandidate().getTotalVotes();
	//		maxId[i] = temp->getCandidate().getID();	// stores max ID
	//		++i;
	//	}
	//	else
	//	{
	//		temp = temp->getLink();
	//	}
	//
	//}
	
	//temp = first; // RESET

	int pos = 0;
	int i = 0;
	while (temp != nullptr)
	{
		++pos;
		++i;
		cout << left << setw(15) << temp->getCandidate().getLastName()
			<< left << setw(10) << temp->getCandidate().getFirstName()
			<< right << setw(5) << temp->getCandidate().getTotalVotes()
			<< right << setw(7) << pos << endl;
	
		temp = temp->getLink();
		
		if (i % 5 == 0)
		{
			cout << "---------------------------------------" << "\n";
		}	
	}

	cout << "_______________________________________" << endl;
}

// clearList
void CandidateList::clearList() 
{
	Node* temp = first;
	while (temp != last)
	{
		temp = temp->getLink();
		delete first; 
		first = temp;
	}

	count = 0;
}

// Destructor
CandidateList::~CandidateList() 
{
	clearList();
}