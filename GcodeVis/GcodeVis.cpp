// GcodeVis.cpp : Defines the entry point for the console application.
//
// Gcode path  LayerThickness  LineWidth
#include "stdafx.h"
#include "visualization\visualizaion.h"
string path;
float LayerThickness, LineWidth;

int main()
{
	Model *resultModel=new Model;
	cin >> path >> LayerThickness >> LineWidth;
	visualizaion::readInGcode(path, resultModel);
	visualizaion::generateModelForRendering("Result", LayerThickness, LineWidth, resultModel);
    return 0;
}

