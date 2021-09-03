#pragma once

#include "stdafx.h"
#include "GeneralMesh.h"
#include "Setting.h"
//#include "visualization\Vector3.h"
//#include "visualization\Vector2.h"
class visualizaion
{
public:
	visualizaion();
	~visualizaion();
	static double getlen(point3D u, point3D v);
	static double getlen(Vec3 u, Vec3 v);
	//static void generateModelForRendering(std::string v_file_name, std::vector<std::vector<double>> *Max_len, std::vector<std::vector<int>> *EveryContour_num, std::vector<std::vector<std::vector<std::vector<point3D>>>> *newModel);
	static void insert_Line(General_Mesh& mesh, std::vector<Vec3> points, float l, float h);
	static void generateModelForRendering(std::string v_file_name, double layerthickness, double linewidth, std::vector<std::vector<point3D>> *newModel);
	static void readInGcode(std::string FILENAME,Model *model);
	static float get_number(string thestring, int st);
	static int get_digiet(char ci);
		//void generateSamplePointLine(vector<vector<samplePoint2D>> in);
};

