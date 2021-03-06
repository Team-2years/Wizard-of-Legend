#pragma once
/*************************************************************
## FloatTriangle ##
@@ Author : ?Ǽ??? , Date : 2019.03.19
**************************************************************/
namespace Figure
{
	class FloatTriangle
	{
	public:
		union
		{
			struct
			{
				Vector2 vertex0;
				Vector2 vertex1; 
				Vector2 vertex2; 
			};
			Vector2 vertex[3];
		};
	public:
		FloatTriangle();
		explicit FloatTriangle(const Vector2& v0, const Vector2& v1, const Vector2& v2);
		~FloatTriangle();

		void Update(const Vector2& v0, const Vector2& v1, const Vector2& v2);
		void Move(const Vector2& moveValue);

		Vector2 GetExternalCenter();
		float GetExternalRadius();
		Figure::FloatEllipse GetExternalEllipse();
	private:
		void SortVertexByX();
	};

}