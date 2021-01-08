#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class PolyNode    //define data type(structure)
{
public:
   int coef;
   int expo;
   PolyNode* next;
};

class PolyLinkedList //Liked list using node.
{
public:
    PolyNode *LinkHead;

    PolyLinkedList()
    {
        LinkHead=NULL;
    }
    void addNode2First(int coef, int expo)
    {
        PolyNode *tmp = new PolyNode();

        tmp->coef = coef;
        tmp->expo = expo;
        tmp->next = LinkHead;

        LinkHead = tmp;
    }

    void sum()
    {
        map< int, int > result;

        PolyNode *tmpPoint = LinkHead;

        while(tmpPoint->next != NULL)
        {
            int coef = tmpPoint->coef;
            int expo = tmpPoint->expo;
            
            if(result.count(expo)==0)
            {
                result.insert(make_pair(expo, coef));
            }
            else
            {
                result[expo] += coef;
            }
            
            tmpPoint = tmpPoint->next;
        }

        int coef = tmpPoint->coef;
        int expo = tmpPoint->expo;
        
        if(result.count(expo)==0)
        {
            result.insert(make_pair(expo, coef));
        }
        else
        {
            result[expo] += coef;
        }
        vector< pair < int, int > > pairs;

        for (map< int, int >::iterator itr = result.begin(); itr != result.end(); ++itr)
        {
            if(itr->second!=0)
            {  
                pairs.push_back(*itr);
            }
        }
        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());

        cout << pairs.size() << endl;

        for (vector<pair<int, int> >::iterator itr = pairs.begin(); itr != pairs.end(); ++itr){
            cout << itr -> second << " " << itr -> first << endl; 
        }
    }
};

void Input(PolyLinkedList *polyadd){
    int coef, expo, noTerm, N;
    cin>>N;

    for(int i=0; i<N; i++)
    {
        cin>>noTerm;

        for(int i=0; i < noTerm; i++)
        {
            cin>>coef; cin>>expo;
            polyadd->addNode2First(coef, expo);
        }
    }
}
int main()
{
    PolyLinkedList *polyadd = new PolyLinkedList();

    Input(polyadd);
    polyadd->sum();

    
    return 0;
}
