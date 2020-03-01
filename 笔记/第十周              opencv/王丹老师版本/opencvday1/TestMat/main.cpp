#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>


using namespace cv;
using namespace std;

#define IMAGE_PATH (IMAGE) "D:/workspaace/testsrc/src/"#IMAGE

string getName(string name)
{
    string path = "D:/workspaace/testsrc/src/";
    return path+name;
}

int main()
{

    vector<string> v;
    for(int i = 1 ; i <6; i++)
    {
        char buf[100];
       sprintf(buf,"%d.jpg",i);
       v.push_back(buf);
    }

    int index = 0 ;
    while(true)
    {
        string p = getName(v[index]);
        cout<<p<<endl;
        Mat img = imread(p);
        if(!img.data)
        {
            cout<<"load image failed"<<endl;
            break;

        }
        imshow("show",img);
        Mat dst;
        cvtColor(img,dst,CV_BGR2GRAY);
        imwrite("gray.png",dst);

        namedWindow("gray");
        imshow("gray",dst);

        int k = waitKey(0);
        if(k == 'a')
        {
            if(index == 0)
            {
                index = 4;
            }else
            {
                index--;
           }

        }else if(k == 'd')
        {
           if(index == 4)
            {
                index = 0;
           }else
           {
                index++;
           }
        }

    }



    return 0;
}

