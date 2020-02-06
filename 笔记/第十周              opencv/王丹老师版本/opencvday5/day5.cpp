
一、膨胀与腐蚀
1、图像形态学操作：
	1.基于形状的一系列图像处理的集合，主要是基于集合论基础上的形态学数学
	2.形态学有四个基本操作：膨胀、腐蚀、开、闭
	3.膨胀与腐蚀是图像处理中最常用的形态学操作手段
2、膨胀：跟卷积操作类似，假设有图像A和结构元素B，结构元素B在A上面移动，其中B定义其中心为锚点，
		计算B覆盖下A的最大像素值用来替换锚点的像素，其中B作为结构体可以是任意形状
		
3、腐蚀：腐蚀跟膨胀操作的过程类似，唯一不同的是以最小值替换锚点重叠下图像的像素值

4、获得结构
Mat getStructuringElement(int shape, 				//结构形状MorphShapes
												  Size ksize, 			//结构尺寸  奇数
												  Point anchor = Point(-1,-1));//结构锚点
												  
5、膨胀
void dilate( InputArray src, 
						 OutputArray dst, 
						 InputArray kernel,
             Point anchor = Point(-1,-1), 
             int iterations = 1,				//膨胀次数
             int borderType = BORDER_CONSTANT,
             const Scalar& borderValue = morphologyDefaultBorderValue() );
             
示例：
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 20));
dilate(src, dst, kernel);
imshow("src", src);
imshow("dst", dst);


6、腐蚀
void erode( InputArray src, 
						OutputArray dst, 
						InputArray kernel,
            Point anchor = Point(-1,-1), 
            int iterations = 1,
            int borderType = BORDER_CONSTANT,
            const Scalar& borderValue = morphologyDefaultBorderValue() );
            
示例：
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 20));
erode(src, dst, kernel);
imshow("src", src);
imshow("dst", dst);

           
                   
8、总结，膨胀可以扩张亮域；腐蚀可以缩减亮域

练习：在qt界面中分别通过两个滑动条来调整膨胀和腐蚀的效果（改变StructuringElement中size的值）

二、形态学操作
1、形态学操作包括：膨胀、腐蚀、开、闭、形态学梯度、顶帽、黑帽

2、
void morphologyEx( InputArray src, 
									 OutputArray dst,
                   int op, 									//形态学类型 MorphTypes
                   InputArray kernel,
                   Point anchor = Point(-1,-1), 
                   int iterations = 1,
                   int borderType = BORDER_CONSTANT,
                   const Scalar& borderValue = morphologyDefaultBorderValue() );
                   
3、开：先腐蚀后膨胀    消除细微的明亮区域

示例：
Mat src = imread(IMAGE_PATH(dilateanderode2.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(31, 31));
morphologyEx(src, dst, MORPH_OPEN, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

4、闭：先膨胀后腐蚀		 消除细微的黑暗区域

示例：
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(37, 37));
morphologyEx(src, dst, MORPH_CLOSE, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

5、形态学梯度：膨胀减腐蚀       提取轮廓

示例：
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 21));
morphologyEx(src, dst, MORPH_GRADIENT, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

6、顶帽：原图像减开操作   得到比原图像更亮的环绕部分

示例：
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 21));
morphologyEx(src, dst, MORPH_TOPHAT, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

7、黑帽：闭操作减原图像   得到比原图像更暗的环绕部分

示例：
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 21));
morphologyEx(src, dst, MORPH_BLACKHAT, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

三、形态学应用

1、消除垂直的直线
Mat src = imread(IMAGE_PATH(lines.jpg));
Mat gray;
cvtColor(src, gray, CV_BGR2GRAY);
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 1));
morphologyEx(gray, dst, MORPH_CLOSE, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

2、消除水平的直线
Mat src = imread(IMAGE_PATH(lines.jpg));
Mat gray;
cvtColor(src, gray, CV_BGR2GRAY);
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(1, 21));
morphologyEx(gray, dst, MORPH_CLOSE, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

3、消除小范围噪声
Mat src = imread(IMAGE_PATH(text.jpg));
Mat grayImg;
cvtColor(src, grayImg, CV_BGR2GRAY);
Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
Mat dst;
morphologyEx(grayImg, dst, MORPH_CLOSE, kernel);
medianBlur(dst, dst, 7);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

四、基本阈值操作

1、什么是阈值？
如果你去菜市场买苹果，你会根据什么挑选？

2、阈值类型
1.阈值二值化 THRESH_BINARY：小于阈值的值置零，大于阈值的值置最大值
2.阈值反二值化 THRESH_BINARY_INV：小于阈值的值置最大值，大于阈值的值置零
3.截断 THRESH_TRUNC：小于阈值的值不变，大于阈值的值置阈值
4.阈值取零 THRESH_TOZERO：小于阈值的值置零，大于阈值的值不变
5.阈值反取零 THRESH_TOZERO_INV：小于阈值的值不变，大于阈值的值置零

3、自动计算阈值的两种算法，只能用在单通道图像，使用算法时会自动计算阈值，参数thresh将失效
THRESH_OTSU
THRESH_TRIANGLE

4、double threshold( InputArray src, 
										 OutputArray dst,
                     double thresh, 		//自定义阈值
                     double maxval, 		//最大值
                     int type );				//阈值类型以及自动计算阈值类型
                     //返回值是自动计算出来的阈值
                     
示例１：阈值二值化

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 127, 255, THRESH_BINARY);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

示例２：阈值反二值化

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 127, 255, THRESH_BINARY_INV);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

示例３：截断

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 70, 255, THRESH_TRUNC);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

示例４：阈值取零

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 70, 255, THRESH_TOZERO);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

示例５：阈值反取零

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 70, 255, THRESH_TOZERO_INV);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

示例６：使用算法自动生成阈值

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
double t = threshold(grayImg, dstImg, 70, 255, THRESH_TOZERO_INV|THRESH_OTSU);
imshow("img", img);
imshow("dst", dstImg);
cout<<t<<endl;
waitKey(0);

练习：阈值二值化，使用Trackbar动态调整阈值来显示效果