
һ��������״������
1��ֱ��
void line(InputOutputArray img, //����ͼƬ
					Point pt1, 						//�˵�1
					Point pt2, 						//�˵�2
					const Scalar& color,	//��ɫ
          int thickness = 1, 		//ֱ�߿��
          int lineType = LINE_8, //ֱ������LINE_4  LINE_8  LINE_AA(�����)
          int shift = 0);				//��������С��λ��

ʾ����
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
line(bg, Point(0, 0), Point(250, 250), Scalar(0, 0, 255));
imshow("test", bg);
          
2������
void rectangle(Mat& img, 							//����ͼƬ
							 Rect rec,							//���εķ�Χ
               const Scalar& color, 	//��ɫ
               int thickness = 1,			//�������
               int lineType = LINE_8, //��������LINE_4  LINE_8  LINE_AA(�����)
               int shift = 0);				//��������С��λ��
  
ʾ����            
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
rectangle(bg, Rect(0, 0, 100, 200), Scalar(0, 0, 255));
imshow("test", bg);
               
3����Բ
void ellipse(InputOutputArray img, 			//����ͼƬ
						 const RotatedRect& box, 		//��Բ�ķ�Χ
						 const Scalar& color,
             int thickness = 1, 
             int lineType = LINE_8);
             
RotatedRect���캯��      
RotatedRect(const Point2f& center, //���ĵ�
					  const Size2f& size, 	 //�ߴ�
					  float angle);					 //�Ƕ�  ˳ʱ��
					  
ʾ����
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
ellipse(bg, RotatedRect(Point(100, 100), Size(100, 50), 30), Scalar(0, 0, 255));
imshow("test", bg);
					  
4��Բ
void circle(InputOutputArray img, 		//����ͼƬ
					  Point center, 						//���ĵ�
					  int radius,								//�뾶
            const Scalar& color, 
            int thickness = 1,
            int lineType = LINE_8, 
            int shift = 0);
            
ʾ����
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
circle(bg, Point(100, 100), 50, Scalar(0, 0, 255));
imshow("test", bg);

5�������
void polylines(InputOutputArray img, 
							 InputArrayOfArrays pts,		//������
               bool isClosed, 						//�Ƿ�պ�  �����һ����͵�һ����������һ��
               const Scalar& color,
               int thickness = 1, 
               int lineType = LINE_8, 
               int shift = 0 );
               
ʾ����
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
vector<Point> points;
points.push_back(Point(0, 0));
points.push_back(Point(10, 10));
points.push_back(Point(0, 20));
points.push_back(Point(20, 0));
points.push_back(Point(30, 30));

polylines(bg, points, true, Scalar(255, 0, 0), 2);

imshow("test", bg);

               
6������
void putText( InputOutputArray img, 
							const String& text, 
							Point org,									//�ı����½�λ��
              int fontFace, 							//����  �ο�HersheyFonts
              double fontScale, 					//����
              Scalar color,
              int thickness = 1, int lineType = LINE_8,
              bool bottomLeftOrigin = false );//�Ƿ�ת
              
ʾ����
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
putText(bg, "hello world", Point(0, 500), FONT_ITALIC, 1, Scalar(0, 0, 255));
imshow("test", bg);

7�����
RNG�����
int uniform(int a, int b);//[a, b)����
float uniform(float a, float b);
double uniform(double a, double b);

ʾ����
RNG rng;
for(int i = 0;i < 10;i++)
{
    cout<<rng.uniform(0, 100)<<endl;
}

��ϰ���������10��ֱ�ߣ���ɫ����ȡ�λ�ö����

Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
RNG rng(time(0));

for(int i = 0;i < 10;i++)
{
    Point p1(rng.uniform(0, 500), rng.uniform(0, 500));
    Point p2(rng.uniform(0, 500), rng.uniform(0, 500));
    Scalar color(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    int width = rng.uniform(1, 5);
    line(bg, p1, p2, color, width, LINE_AA);
}

imshow("test", bg);

����ģ��ͼ��
1����ֵ�˲���  �������е��ƽ��ֵ

void blur( InputArray src, 
					 OutputArray dst,
           Size ksize, 		//�ˣ����ڣ��ߴ�   �ߴ�Ϊ����
           Point anchor = Point(-1,-1), //ê�㣬Ĭ��Ϊ�е�
           int borderType = BORDER_DEFAULT );//�߿����Ʒ�ʽBorderTypes

1	1	1	1	1
1	1	1	1	1
1	1	1	1	1
1	1	1	1	1
1	1	1	1	1

ʾ����
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
blur(src, dst, Size(7, 7));
imshow("src", src);
imshow("dst", dst);


2����˹�˲���  
��˹ƽ�����������ڵ����ص����Ϊ��˹�ֲ�

void GaussianBlur( InputArray src, 
									 OutputArray dst, 
									 Size ksize,			//�ˣ����ڣ��ߴ�  �ߴ�Ϊ����
                   double sigmaX, 	//x����ϵ��  ���Ϊ0����ݹ�ʽ�Զ�����ϵ��
                   double sigmaY = 0,//y����ϵ��  ���Ϊ0����ݹ�ʽ�Զ�����ϵ��
                   int borderType = BORDER_DEFAULT );
                   
1		4		7		4		1
7		26	41	26	7	
1		4		7		4		1

ʾ����
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
GaussianBlur(src, dst, Size(7, 7), 0, 0);
imshow("src", src);
imshow("dst", dst);

                   
3����ֵ�˲���	�������ڵ����ص����򣬽���������м��ֵ�滻�����м�����ص㣨�Խ�������Ч���Ϻã�

void medianBlur( InputArray src, 
								 OutputArray dst, 
								 int ksize );
								 
ʾ����
Mat src = imread(IMAGE_PATH(head4.jpg));
Mat dst;
medianBlur(src, dst, 7);
imshow("src", src);
imshow("dst", dst);

4��˫���˲��� 
˫��ƽ�����Դ����ڸ����ص���м�Ȩƽ����Ȩ������������ɣ�1.ͬ��˹ƽ�� 2.��˹Ȩ�ء�
���Խ�˫��ƽ�������Ǹ�˹ƽ����ֻ�����Ƴ̶ȸ��ߵ�����Ȩֵ���ߣ���Ե���������Աȶȸ��ߡ�

��Ȩƽ������Ȩƽ��ֵ��������ֵ������Ӧ��Ȩ����Ȼ�������͵õ�����ֵ���ٳ����ܵĵ�λ����

void bilateralFilter( InputArray src, 
										  OutputArray dst, 
										  int d,							//���ڴ�С  ���dֵС��0�������sigmaSpace�Զ�����
                      double sigmaColor, 	//��ɫ�ռ��˲�ϵ��  ֵԽ��Խ���׺���Χ���ػ�ϣ��Աȶ�Խ�ͣ�
                      double sigmaSpace,	//����ռ��˲�ϵ��  ����Ĵ�С��d������ʱӦ�ú�d��������
                      int borderType = BORDER_DEFAULT );
                      
ʾ����
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
bilateralFilter(src, dst, 15, 100, 15);
imshow("src", src);
imshow("dst", dst);

��ϰ1����ͼƬ����˫���˲���Ȼ��ʹ��filter2D��ǿͼƬ�Աȶ�

��ϰ2��������ͷ��������ͷ�е��Լ����С����ա�


����ֱ��ͼ��Histogram��
1��ͼ��ֱ��ͼ����ָ������ͼ���ڻҶȷ�Χ�ڵ�����ֵ(0~255)ͳ�Ƴ���Ƶ�ʴ������ݴ����ɵ�ֱ��ͼ��
		��Ϊͼ��ֱ��ͼ-ֱ��ͼ��ֱ��ͼ��ӳ��ͼ��Ҷȵķֲ��������ͼ��ġ�ͳ��ѧ��������
		
2��ֱ��ͼ��ֵ������һ�����ͼ��Աȶȵķ���������ͼ��Ҷ�ֵ��Χ��
1.���ʵ�֣�ͨ����ͨ������ӳ��remap����֪�����Խ�ͼ��Ҷȷֲ���һ���ֲ�ӳ�䵽����һ���ֲ���
		Ȼ���ڵõ�ӳ��������ֵ���ɡ�
2.
void equalizeHist( InputArray src, 
									 OutputArray dst );	

ʾ����
Mat src = imread("d:/farsight/opencv/testres/head1.png");
Mat gray, dst;
cvtColor(src, gray, CV_BGR2GRAY);
imshow("gray", gray);
equalizeHist(gray, dst);
imshow("dst", dst);							 
									 						 
3������ֱ��ͼ
1.����ͨ�����黮��Ϊ�����ͨ������
void split(const Mat& src, 
				   Mat* mvbegin);
				   
2.����ֱ��ͼ
void calcHist( const Mat* images,  //Ҫ����ֱ��ͼ��Mat���飬���ԶԶ��ͼ��ͬʱ���з����õ�һ��ֱ��ͼ
							 int nimages,				 //images�����Ԫ�ظ���
               const int* channels, //ÿ��ͼƬҪ�����ͨ��
               InputArray mask,			//��Ĥ���飬������8-bit���鲢����images�е�����ͬsize���������Ҫ��Ĥ��cv::noArray()
               OutputArray& hist, 	//���ֵ����һ��һά����
               int dims,						//ֱ��ͼ��ά�ȣ�ǡ����channels�����Ԫ�ظ���
               const int* histSize,  //ֱ��ͼÿ��ά�ȵ�����ĸ���(���ֵhist�����鳤��)  int size[n];
               const float** ranges,	//ֱ��ͼÿ��ά�ȵ���Ҫͳ�Ƶ�ֵ�ķ�Χ�������20��30�����ǰ�20~30ǰ�պ������ֵ������ͳ�ƣ�Ӧ����ɶ�ά���飬���鳤�ȱ���Ϊdims		float range1[] = {0, 1000}; const float* ranges[] = {range1};
               bool uniform = true,  //ranges�е����ݵĽ��ͷ�ʽ��һ��ѡtrue
               bool accumulate = false );//��imagesת��Ϊֱ��ͼ֮ǰ��Ҫ������Ԫ��ɾ��
               
3.��һ�����������е�ֵ���ձ�������
void normalize( InputArray src, 
							  InputOutputArray dst, 
							  double alpha = 1, 			//��һ��ÿ��Ԫ�ص���Сֵ
							  double beta = 0,				//��һ��ÿ��Ԫ�ص����ֵ
                int norm_type = NORM_L2,//NORM_MINMAX ���ձ������ŷ�ʽ�����й�һ������
                int dtype = -1, 				//���ֵ��-1��ԭ������һ��
                InputArray mask = noArray());//����

ʾ����
Mat src = imread("d:/farsight/opencv/testres/head1.png");
Mat signal_images[3];
split(src, signal_images);//������ͨ�����룬��ŵ�signal_images��
int channel = 0;
Mat dst;
int size = 500;
float range[2] = {0, 256};
const float* ranges[1] = {range};
Scalar colors[3] = {Scalar(255,0,0),Scalar(0,255,0),Scalar(0,0,255)};
char* showTitles[3] = {"showB","showG","showR"};
for(int i = 0;i < 3;i++)
{
    calcHist(&signal_images[i], //ֻ��һ��ά��������ֱ��ͼ
    1, //����Ԫ�ظ���Ϊ1
    &channel,//��Ϊ����Matֻ��һ��ͨ��������ֻ��ѡ��0ͨ��
    noArray(),//��Ҫ��Ĥ����
    dst,//���
    1,//��Ϊ�����Mat����ά����1
    &size,//����500������
    ranges);//ͳ�Ʒ�Χ��0~256ǰ�պ�����
    //��һ��
    normalize(dst, dst, 0, 100, NORM_MINMAX);
    int showWidth = dst.size().height;//height��dst�����鳤��
    int showHeight = 300;
    Mat showImg(Size(showWidth, showHeight), CV_8UC3);
    for(int j = 0;j < showWidth;j++)
    {
        line(showImg,Point(j, showHeight-dst.at<float>(j)),Point(j, showHeight),colors[i],1,LINE_AA);
    }
    imshow(showTitles[i], showImg);
}