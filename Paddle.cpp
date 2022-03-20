#include "Paddle.h"

Paddle::Paddle(
	Vector2 position,
	float height,
	float width,
	float speed,
	Vector2 direction,
	Vector4 color
)
	:position(position),
	height(height),
	width(width),
	speed(speed),
	direction(direction),
	color(color)
{
	topLeft = Vector2(
		position.x,
		position.y
	);

	bottomRight = Vector2(
		position.x + width,
		position.y + height
	);
}

void Paddle::UpdatePaddle(float deltaTime, float windowHeight, float windowWidth)
{
	if (direction.x != 0)
	{
		position.x += direction.x * speed * speedFactor * deltaTime;

		if (position.x < 0)
			position.x = 0;

		else if (position.x + width > windowWidth)
			position.x = windowWidth - width;
	}
}

void Paddle::Draw(SDL_Renderer* renderer) 
{
	SDL_SetRenderDrawColor(
		renderer,
		color.x,
		color.y,
		color.w,
		color.z
	);

	SDL_Rect paddle{
		static_cast<int>(position.x),
		static_cast<int>(position.y),
		static_cast<int>(width),
		static_cast<int>(height)
	};

	SDL_RenderFillRect(renderer, &paddle);
}