#pragma once
#include <vector>
#include <string>
#include <utility>

class graphs {
public:
	graphs() = default;
	graphs(const std::string& name, int width, int height, int horizRes, int vertRes) :
		name(name), width(width), height(height), horizRes(horizRes), vertRes(vertRes) {}
	std::pair<int, int> getRes() const { return { horizRes, vertRes }; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	std::string getName() const { return name; }
	virtual int size() const = 0;
	virtual ~graphs() = default;
protected:
	int width = 0;
	int height = 0;
	int horizRes = 0;
	int vertRes = 0;
private:
	std::string name;
};

class jpeg : public graphs {
public:
	jpeg() = default;
	jpeg(const std::string& name, int width, int height, int horizRes, int vertRes) :
		graphs(name, width, height, horizRes, vertRes) {}
	int size() const override;
	~jpeg() = default;
private:
	double compression = 0.0;
};

class bmp : public graphs {
public:
	bmp() = default;
	bmp(const std::string & name, int width, int height, int horizRes, int vertRes) :
		graphs(name, width, height, horizRes, vertRes) {}
	int size() const override;
	~bmp() = default;
};

class gif : public bmp {
public:
	gif() = default;
	gif(const std::string & name, int width, int height, int horizRes, int vertRes, std::vector<bmp> bmps) :
		bmp(name, width, height, horizRes, vertRes), bmps(bmps) {}
	void push_bmp(const bmp& g) { bmps.push_back(g); }
	void pop_bmp() { bmps.pop_back(); }
	int size() const override;
	~gif() = default;
private:
	std::vector<bmp> bmps;
	int speed = 0;
};