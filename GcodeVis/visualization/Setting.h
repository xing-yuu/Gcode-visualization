#pragma once
#include"stdafx.h"
#include<vector>

struct point3D {
	float x;
	float y;
	float z;
	float xn, yn;//法向量
	point3D operator + (const point3D& b)
	{
		point3D temp = b;
		temp.x += x;
		temp.y += y;
		temp.z += z;
		return temp;
	}
	point3D operator + (const int& b)
	{
		point3D temp = *this;
		temp.x += b;
		temp.y += b;
		temp.z += b;
		return temp;
	}
	point3D operator - (const point3D& b)
	{
		point3D temp = *this;
		temp.x -= b.x;
		temp.y -= b.y;
		temp.z -= b.z;
		return temp;
	}
	point3D operator - (const int& b)
	{
		point3D temp = *this;
		temp.x -= b;
		temp.y -= b;
		temp.z -= b;
		return temp;
	}
	point3D operator / (const double& b)
	{
		point3D temp = *this;
		temp.x /= b;
		temp.y /= b;
		temp.z /= b;
		return temp;
	}
	point3D operator * (const double& b)
	{
		point3D temp = *this;
		temp.x *= b;
		temp.y *= b;
		temp.z *= b;
		return temp;
	}
};

/*
std::map<std::string, int> texture{
		{ "Pattern0",0 },
		{ "Pattern1",1 },
		{ "Pattern2",2 },
		{ "Pattern3",3 },
		{ "Pattern4",4 },
		{ "Pattern5",5 },
		{ "Pattern6",6 },
		{ "Pattern7",7 },
		{ "Pattern8",8 },
		{ "Pattern9",9 },
};
*/



typedef std::vector<point3D> Layer;
typedef std::vector<Layer> Model;


class Setting {
	public:
	//砖块相关
		double g_BrickWidth;//墙砖的宽度 单位：mm
		double g_BrickHeight;//墙砖的高度 单位：mm
		double g_BrickThickness;//墙砖的厚度 单位：mm
		double g_CircleRadius;//弧面对应的圆的半径
		double g_SupportsNumber;//支撑的数目
		double g_LayerThickness;//层厚
		int g_LayersNumber;//层数
	
	


//打印机相关
	std::string g_PrinterID;//打印机种类
	double g_LineWidth;//线宽
	double g_PrinterSpeed;//打印机速度
	double g_ExtruderDiameter;//打印机头的直径
	double g_CentralX;//打印机中心X坐标
	double g_CentralY;//打印机中心Y坐标
	double g_ExtrusionRate;//挤出率

	std::string outputFilePath;//输出文件的路径
	std::string visualizationOutputFilePath;//可视化结果输出文件的路径


	int g_Texture;//纹理种类
	std::string g_TextureName;
	double g_TextureAmplitude;//纹理的振幅，单位：mm
	int g_HorizontalCyclesNumber;//水平方向纹理的周期数目
	int g_VerticalCyclesNumber;//垂直方向纹理的周期数目
	int g_PointDensity;//一周期内点的密度

//	void Readin_configure(std::string CONGFIGPATH);

};
