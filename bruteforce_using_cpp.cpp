#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;

void generate_init_list(char *match_list)
{
    for (int i = 0; i < 94; i++)
    {
        match_list[i] = (char)(i+33);
    }
}

int calculate_dynamic_arr_size(int n, int sel)
{
    if(sel == 1)
        return pow(94,n);
    if(sel == 2)
        {
            int l = 94;
            for(int i = 1; i < (n+1); i++)
            {
                l = l + pow(94,i);
            }
            return l;
        }
    return 0;
}

void add_char_to_list_strings(char** list, int* size, int dynamic_arr_size, char* match_list)
{
    char* temp = NULL;
    int index_temp = 0;
    int n = log10(dynamic_arr_size)/log10(94);
    int z = 0;
    int count = 0;
    int count_loop_run = 0;
    for (int j = 1; j <= n; j++)
    {
        count = 0;
        for (int i = 0; i < dynamic_arr_size; i++)
        {
            if ((n - j) == 0)
            {
                count = 0;
                if (z == 93)
                {
                    z = 0;
                }
                else z++;
            }
            if (count == pow(94, n - j) && (n - j) != 0)
            {
                count = 0;
                if (z == 93)
                {
                    z = 0;
                }
                else
                    z++;
            }
            if(count_loop_run == 93)
            {
                count_loop_run = 0;
                break;
            }
            temp = list[i];
            temp[j - 1] = match_list[z];
            count++;
            
        }
    }
}
void generate_list_fixed_n(char** list, char* match_list, int dynamic_arr_size, int n)
{
    int size;
    if (n == 1)
        for (int i = 0; i < 94; i++)
        {
            *list[i] = match_list[i];
        }
    else
    {
        for (int i = 1; i < n; i++)
        {
            add_char_to_list_strings(list, &size, dynamic_arr_size, match_list);
        }
    }  
}

int main()
{
    int n, sel, save;
    int dynamic_arr_size;
    char match_list[94];
    char** list;
    cout<<"Enter length of ASCII string permutations to generate : "<<endl;
    cin>>n;
    sel = 2;
    char path_file_name[100];
    cout<<"Enter file name to save data in : ";
    cin>>path_file_name;
    generate_init_list(match_list);
    for(int i = 0; i < 94; i++)
    dynamic_arr_size = calculate_dynamic_arr_size(n, sel);
//    list = (char *)malloc(n * dynamic_arr_size *sizeof(char));
    list = new char* [dynamic_arr_size];
    for(int i = 0 ; i < dynamic_arr_size; i++)
    {
        list[i] = new char[n];
    }
    generate_list_fixed_n(list, match_list, dynamic_arr_size, n);
    int count = 0;
//   vector<char> vector_list = list;
    ofstream this_file;
    this_file.open(path_file_name);
    for(int i = 0; i < dynamic_arr_size; i++)
    {
        cout<<list[i]<<endl;
        this_file << list[i] << endl;
        count++;
    }
    cout<<count<<endl;;
    this_file.close();
    delete list;
    list = NULL;
    
    
}

