

__interrupt double compute_area(double radius)
{
	double area = PI * radius * radius;
	printf(“nArea = %f”, area);
	return area;
}
