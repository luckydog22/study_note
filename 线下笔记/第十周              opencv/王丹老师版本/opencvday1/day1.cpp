
OpenCV��һ������BSD��ɣ���Դ�����еĿ�ƽ̨������Ӿ��⣬
����������Linux��Windows��Android��Mac OS����ϵͳ�ϡ�
�����������Ҹ�Ч������һϵ�� C ���������� C++ �๹�ɣ�ͬʱ�ṩ��Python��Ruby��MATLAB�����ԵĽӿڣ�
ʵ����ͼ����ͼ�����Ӿ�����ĺܶ�ͨ���㷨��

һ���������ú͵�һ��opencv��Ŀ

qt-opencv������¼.doc

INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include\opencv
INCLUDEPATH += D:\opencv\opencv3.4-qt-install\install\include\opencv2
LIBS += D:/opencv/opencv3.4-qt-install/install/x86/mingw/lib/libopencv_*.a


dll ��̬��  ��̬���ӿ�  ���е�ʱ��
LIBS ��̬��  ����ʱ�õ�

����������������

//1.����mat����  ��ȡͼƬ����
��֮���ͼƬ�Ĳ������Ͷ�mat���������������޷�ֱ��ʶ��ͼ��
//���·��  ����·��������
  Mat src = imread("1.pgm");  

//2.�ж���ȡ�Ƿ�ɹ�
��1��src.data==0;
��2��src.empty()==false;

//3.������ʾ����
//           �������� �� �����ô��ڴ�С����������Ӧ 
namedWindow("src",CV_WINDOW_AUTOSIZE);  

//4.�ڴ�����ʾͼƬ
//  ��������, ͼƬ����  
imshow("dst",dst);

//5.ת��ͼ��ɫ�ʿռ䣨��ɫ--����ɫ��  ��ͨ��תΪ��ͨ����Ч�ʸ�
Mat dst;  //����һ���������洢ת�����ͼƬ
		//ԭͼƬ����  �洢��Ŀ�����   Ŀ����ɫ������õĺ꣩
cvtColor(src,dst,CV_BGR2GRAY);

//6.����ͼƬ��ֻ�е�ͨ����ͼƬ���󣬲ſ�����imwrite��
		//ԭͼƬ   Ŀ��ͼƬ
imwrite("gray.png",dst);
		//��ʽ������ͼƬ
imwrite( format("z%d.jpg",cout) );




#include <opencv2/opencv.hpp>  //ͷ�ļ�  ��ǿ�ļ�

1.opencv�б�ʾͼ�����Mat  // Mat ������ʾͼƬ

2.����ͼ��
Mat imread( const String& filename, int flags = IMREAD_COLOR );

imread�����Ǽ���ͼ���ļ���Ϊһ��Mat����

����1��ͼƬ��·����ͼ���ļ�����
����2��ͼ���ɫ�ʿռ�ģʽ��Ĭ��ΪBGR��
		�ڶ���������ʾ���ص�ͼ����ʲô���ͣ�֧�ֳ�������������ֵ
		
����ֵ��ͼ�����

//ע�⣺opencv֧��jpg��png��tiff�ȳ�����ʽͼ���ļ�����
�궨�壺#define IMAGE_PATH (IMAGE) "D:/workspaace/testsrc/src/"#IMAGE

3.��������

void namedWindow(const String& winname, int flags = WINDOW_AUTOSIZE);
����1�����ڵ����ƣ�Ӣ�ģ�
����2���������ԣ�Ĭ��Ϊ����ͼ�����ô��ڳߴ�

4.ת��ͼ��ɫ�ʿռ� �޸�ͼ��  //  ����ͨ���� ת�ɵ�ͨ�� Ч�ʸ� 
void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );
����1������ͼ��
����2�����ͼ��
����3��ɫ�ʿռ�  ����ColorConversionCodes
����4��ͨ������Ĭ�ϸ���ɫ�ʿռ����

eg��ת�Ҷ� 
    Mat src = "D:/workspaace/testsrc/68.jpg";
    if(!src.data)
    {
        cout<<"load image failed"<<endl;
    }
    
    imshow("src",src);
    //ת�Ҷ�
    Mat dst;
    cvtColor(src,dst,CV_BGR2GRAY);
    imwrite("gray.png",dst);

    namedWindow("gray");//,cv_window_autosize
    imshow("gray",dst);
    waitKey(0);
    return 0;
	
eg2����ȡһ��ͼƬ
    namedWindow("show");
    string p = "D:/workspaace/testsrc/src/1.jpg";
    Mat img = imread(p);
    if(!img.data)
    {
        cout<<"load image failed"<<endl;

    }
    imshow("show",img);
    waitKey(0);

5.����ͼ��
bool imwrite( const String& filename, InputArray img,
              const std::vector<int>& params = std::vector<int>());
����1��ͼƬ�ļ�������
����2�������ͼ�����
����3��������һ�㲻��Ҫָ����
ע�⣺ֻ��8λ��16λ��PNG��JPG��Tiff�ļ���ʽ�����ǵ�ͨ��������ͨ����BGR��ͼ��ſ���ͨ�����ַ�ʽ����

6.��������
int waitKey(int delay = 0);
����1���ȴ������ʱ�䣬Ĭ��0һֱ�ȴ�
����ֵ��

7.�ڴ�����ʾͼ��
void imshow(const String& winname, const ogl::Texture2D& tex);
����1����������
����2��ͼ�����

��ϰ����һ��ͼƬ�鿴�����ü���a��d�����л�ͼƬ  ʹ��vector<string> v;����ͼƬ����
��ϰ2���½�һ��Qt��Ŀ����������һ����ť����������������button������namedWindow���ڣ���ʾͼƬ���ü���a��d�����л�ͼƬ
 		
��Ŀʾ��1��TestMat
��Ŀʾ��2��TestMat2
eg1:
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
eg2:
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

//��ϰ2ʹ�ã�
		
 QStringList entryList;//���ָ��·�������е��ļ���
  
 QString path = "D:/workspaace/testsrc/src/";//ָ��·��
	
	int index = 2;//�ص�Ҫע�⣺��2��ʼ��ǰ������.��
ʹ�ã�
  QDir dir(path); 

  entryList = dir.entryList(); 	
  
eg:

//ͷ�ļ���
  QStringList entryList;
    QString path ;
    int index ;
//���캯����
 path = "D:/workspaace/testsrc/src/";
    index = 2;
    QDir dir(path);
    entryList = dir.entryList();

//button����¼���
namedWindow("show");
    while(true)
    {
        QString fileName = entryList[index];
        QString name = path+fileName;
        Mat img = imread(name.toStdString());
        if(!img.data)
        {
             qDebug()<<name;
            qDebug()<<"load failed";
            break;
        }
        imshow("show",img);
        int key = waitKey(0);
        if(key == 'a')
        {
            if(key == 2)
            {
                index = entryList.size()-1;
            }else
            {
                index--;
            }
        }else if(key == 'd')
        {
            if(index == entryList.size()-1)
            {
                index = 2;
            }else
            {
                index++;
            }
        }

    }
	

����������Ƶ

1.��Ƶ��VideoCapture

2.����Ƶ
bool open(const String& filename);
����1����Ƶ·��
����ֵ���򿪳ɹ�

3.��ȡ��Ƶ֡
VideoCapture& operator >> (CV_OUT Mat& image);
����1����ȡ��Mat����
����ֵ��VideoCapture����

ʾ����
include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define IMAGE_PATH(IMAGE) "d:/farsight/opencv/testres/"#IMAGE

int main()
{
    VideoCapture cap;
    if(!cap.open(IMAGE_PATH(test.avi)))
    {
        cout<<"��Ƶ�ļ�û���ҵ�"<<endl;
        return 0;
    }
    namedWindow("test");
    Mat frame;
    while(1)
    {
        cap>>frame;
        if(frame.empty())//!frame.data
            break;
        imshow("test", frame);
        if(waitKey(50)>=0)
            break;
    }
    waitKey(0);
    return 0;
}

��ϰ2��������Ƶ�ļ���ÿ��һ�μ����л�һ֡
ʾ����TestMat2

VideoCapture vc;
    QString str = path_video+"snow.mp4";
    if(!vc.open(str.toStdString()))
    {
        qDebug()<<"open fail";
    }
   namedWindow("test");
    while(true)
    {
        Mat frame;
        vc>>frame;
        if(!frame.data)
        {
            qDebug()<<"load failed";
            break;
        }
        imshow("test",frame);
        int k = waitKey(0);
        if(k>='a' && k<= 'z')
        {
             imshow("test",frame);
        }
    }


 
 















