#include "stdafx.h"
#include "visualizaion.h"

using namespace std;

visualizaion::visualizaion()
{
}


visualizaion::~visualizaion()
{
}
double visualizaion::getlen(point3D u, point3D v) {
	return sqrt((u.x - v.x)*(u.x - v.x) + (u.y - v.y)*(u.y - v.y));
}
double visualizaion::getlen(Vec3 u, Vec3 v) {
	return sqrt((u.m_x - v.m_x)*(u.m_x - v.m_x) + (u.m_y - v.m_y)*(u.m_y - v.m_y));
}
void visualizaion::insert_Line(General_Mesh & mesh, std::vector<Vec3> points, float l, float h){
	if (points.size() < 2)
		return;

	for (int i = 0; i < points.size() - 1; i++)
	{

		Vec3 v0 = points[i];
		Vec3 v1 = points[i + 1];

		Vec3 t_dir = v1 - v0;

		Vec3 scale(l / 2, h / 2, t_dir.Length());//宽，高，长度
		Vec3 trans = (v0 + v1) / 2;


		//vector<Vec3> c_vertex = mesh.meshScale(scale, mesh.cylinder_vertex);
		vector<Vec3> c_vertex = mesh.meshScale(scale, mesh.cylinder_vertex);
		c_vertex = mesh.meshRotate(t_dir, c_vertex);
		c_vertex = mesh.meshTrans(trans, c_vertex);
		mesh.insert(c_vertex, mesh.cylinder_faces);
	}
}


void visualizaion::generateModelForRendering(std::string v_file_name, double layerthickness, double linewidth, std::vector<std::vector<point3D>> *newModel)
{
	//	(MaxPoint_len, EveryContour_num, Result, Risk_color)
	General_Mesh mesh1, mesh2, mesh3, mesh4;
	
	for (int layerIdx = 0; layerIdx < newModel->size(); layerIdx++) {
		cout << "rendering \t" << layerIdx + 1 << "/" << newModel->size() << endl;
		std::vector<Vec3> points;
		for (int pointIdx = 0; pointIdx < newModel->at(layerIdx).size(); pointIdx++) {
			Vec3 vi;
			vi.m_x = newModel->at(layerIdx).at(pointIdx).x;
			vi.m_y = newModel->at(layerIdx).at(pointIdx).y;
			vi.m_z = newModel->at(layerIdx).at(pointIdx).z;
			points.push_back(vi);
		}
		points.push_back(points.at(0));
		insert_Line(mesh1, points, linewidth, layerthickness);
	}

	//mesh1.genResultMesh(v_file_name + ".obj");
	mesh1.genResultMesh_Nocolor(v_file_name  + ".obj");
}
int visualizaion::get_digiet(char ci) {
	if (ci == '0') return 0;
	if (ci == '1') return 1;
	if (ci == '2') return 2;
	if (ci == '3') return 3;
	if (ci == '4') return 4;
	if (ci == '5') return 5;
	if (ci == '6') return 6;
	if (ci == '7') return 7;
	if (ci == '8') return 8;
	if (ci == '9') return 9;
}
float visualizaion::get_number(string thestring, int st) {
	float the_number = 0, the_float = 0, weight = 0.1;
	while (thestring[st] >= '0' && thestring[st] <= '9') {
		int ci = get_digiet(thestring[st++]);
		the_number = the_number * 10 + ci;
	}
	if (thestring[st++] == '.') {
		while (thestring[st] >= '0' && thestring[st] <= '9') {
			int ci = get_digiet(thestring[st++]);
			the_float = the_float + (ci)* weight;
			weight *= 0.1;
		}
	}
	return the_number + the_float;
}
void visualizaion::readInGcode(std::string FILENAME,Model *model) {

	//	startGcode->push_back("G0 F1800 X89.7852 Y106.427 Z0.5");
	//   QString now_string;
	vector<point3D> now_layer;
	now_layer.clear();
	bool haveG0 = false;
	float lastORIE = 0, lastNOWE = 0;
	ifstream infile(FILENAME);
	//输出文件
	ofstream outfile("RE_" + FILENAME);

	string str;
	while (getline(infile, str)) {
		float nowe, nowf;
		if (str.find("G1") != str.npos && str.find("X") != str.npos && str.find("Y") != str.npos && str.find("Z") != str.npos ) {
			int start_tip = 0;
			point3D now_point;
			if (str.find("F") != str.npos) {
				while (str[start_tip++] != 'F');
				nowf = get_number(str, start_tip);
			}
			while (str[start_tip++] != 'X');
			now_point.x = get_number(str, start_tip);
			while (str[start_tip++] != 'Y');
			now_point.y = get_number(str, start_tip);
			while (str[start_tip++] != 'Z');
			now_point.z = get_number(str, start_tip);
			while (str[start_tip++] != 'E');
			nowe = get_number(str, start_tip);
			now_layer.push_back(now_point);
		}
		if (str.find(";LAYER:") != str.npos) {
			if (now_layer.size() == 0) continue;
			model->push_back(now_layer);
			now_layer.clear();
			continue;
		}
	}
}