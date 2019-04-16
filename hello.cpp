#include <iostream>
using namespace std;

struct Node
  {
    char ad[20];
    char soyad[20];
    int f1,f2,f3,f4,f5,k1,k2,k3,k4,k5;
    int bal;
    double kredit;
    Node *next;     
  };
  Node *start_ptr = NULL;

void add_node_at_end ()
  {
  Node *temp, *temp2; 
  temp = new Node;
  cout << "Telebenin adini daxil edin : ";
  cin >> temp->ad;
  cout << "Telebenin soyadini daxil edin : ";
  cin >> temp->soyad;
  cout <<endl<< "1ci fenninin balini daxil edin : ";
  cin >> temp->f1;
  cout << "1ci fenninin kreditin sayi : ";
  cin >> temp->k1;
  cout <<endl<< "2ci fenninin balini daxil edin : ";
  cin >> temp->f2;
  cout << "2ci fenninin kreditin sayi : ";
  cin >> temp->k2;
  cout <<endl<< "3ci fenninin balini daxil edin : ";
  cin >> temp->f3;
  cout << "3ci fenninin kreditin sayi : ";
  cin >> temp->k3;
  cout <<endl<< "4ci fenninin balini daxil edin : ";
  cin >> temp->f4;
  cout << "4ci fenninin kreditin sayi : ";
  cin >> temp->k4;
  cout <<endl<< "5ci fenninin balini daxil edin : ";
  cin >> temp->f5;
  cout << "5ci fenninin kreditin sayi : ";
  cin >> temp->k5;
  cout << endl;
  cout<<endl<<"=========================================================="<<endl<<endl;
  temp->kredit=temp->k1+temp->k2+temp->k3+temp->k4+temp->k5;
  cout<<"Kredit sayi : "<<temp->kredit<<endl;
  temp->bal=((temp->f1*temp->k1)+(temp->f2*temp->k2)+(temp->f3*temp->k3)+(temp->f4*temp->k4)+(temp->f5*temp->k5))/(temp->k1+temp->k2+temp->k3+temp->k4+temp->k5);
  cout<<temp->soyad<<" "<<temp->ad<<" in ortalama bali : "<<temp->bal<<endl<<endl<<endl;

  temp->next = NULL;
  if (start_ptr == NULL)
     start_ptr = temp;
  else
    {
      temp2 = start_ptr; 
      while (temp2->next != NULL)
        temp2 = temp2->next; 
      temp2->next = temp;
    }
  } 

void delete_start_node()
  {
    Node *temp;
    temp = start_ptr;
    start_ptr = start_ptr->next;
    delete temp;
  } 
  
void delete_end_node()
  {
    Node *temp1, *temp2;
    if (start_ptr == NULL)
      cout << "yoxdur!" << endl;
      else
        {
          temp1 = start_ptr;
          if (temp1->next == NULL)
            {  
              delete temp1;
              start_ptr = NULL;
            }
            else
              {
                while (temp1->next != NULL)
                  {
                    temp2 = temp1;
                    temp1 = temp1->next;
                  }
                delete temp1;
                temp2->next = NULL;
              }
            }
  } 

void print_node()
  {
    Node *temp;
    temp = start_ptr;
    if(temp == NULL) cout << "yoxdur!" << endl;
    cout<<"=================================================="<<endl;
    cout<<"=============TELEBELERIN SIRALANMASI=============="<<endl;
    cout<<"==================================================="<<endl;
    while(temp != NULL)
      {
        if(temp == NULL) cout << "yoxdur!" << endl;
        cout << "Telebe adi   : " << temp->ad << endl;
        cout << "Ortalama bal : " << temp->bal << endl;
        cout << "Kredit       : " << temp->kredit << endl;
        cout << endl;  
        temp = temp->next; 
      }           
  } 

Node* remove_next(Node* prev)
{
    if(prev)
    {
        if( prev->next )
        {
            Node* temp = prev->next;
            prev->next = temp->next;
            return temp;
        }
    }
    else if(start_ptr)
    {
        Node* temp = start_ptr;
        start_ptr = start_ptr->next;
        return temp;
    }

    return NULL;
}

void sort_age()
{
    Node* start_ptr2 = NULL;

    while(start_ptr)
    {
        Node* prev = NULL;
        Node* curr = start_ptr;
        Node* prevMax = NULL;
        int max = start_ptr->bal;

        while(curr)
        {
            if(curr->bal < max )
            {
                max = curr->bal;
                prevMax = prev;
            }
            prev = curr;
            curr = curr->next;
        }
        
        Node* xferNode = remove_next(prevMax);
        if( xferNode )
        {
            xferNode->next = start_ptr2;
            start_ptr2 = xferNode;
        }
    }
    start_ptr = start_ptr2;
}

int main()
{
aa: int n;
    cout << "Telebe sayi >>";
    cin >> n;
    for(int i = 0; i <= n-1; i++)
      {
        add_node_at_end();      
      }
    print_node();
bb: sort_age();
    print_node();  

    int t;
    cout<<"================================="<<endl;
    cout<<"============ MENU ==============="<<endl;
    cout<<"================================="<<endl;
    cout<<"================================="<<endl;
    cout<<"======1.TELEBE Yarat============="<<endl;
    cout<<"======2.TELEBE Siralanmasi======="<<endl;
    cout<<"======3.CIXIS===================="<<endl;
    cout<<"================================="<<endl;
    cout<<"================================="<<endl;
    cout<<"================================="<<endl;
    cout<<"================================="<<endl;
    cin>>t;
    if (t==1){
    	goto aa;
	}
	if (t==2){
		goto bb;
	}
	else{
		return 0;
	}
    return 0;
}
