//Rojin Radmehr
#include "stdafx.h"
#include "CharacterTab.h"

void CharacterTab::initText()
{
	//Text
	this->infoText.setFont(this->font);
	this->infoText.setCharacterSize(gui::calcCharSize(this->vm, 80));
	this->infoText.setFillColor(sf::Color(255, 255, 255, 255));
	this->infoText.setPosition(this->back.getPosition().x + 20.f, this->back.getPosition().y + 20.f);

	this->infoText.setString(this->player.toStringCharacterTab());
}

CharacterTab::CharacterTab(sf::VideoMode& vm, sf::Font& font, Player& player)
	: Tab(vm, font, player, false)
{
	//Background
	this->back.setFillColor(sf::Color(0, 0, 0, 255));
	this->back.setSize(sf::Vector2f(gui::p2pX(150.f, this->vm), static_cast<float>(this->vm.height)));

	this->initText();
}

CharacterTab::~CharacterTab()
{

}

void CharacterTab::update()
{
	if (!this->hidden)
	{
		//Update the character info
		this->infoText.setString(std::string("Hello! Welcome to Campus Run!"
			"\n You are a Bachelor student in the Building 103."
			"\n You open your refrigerator and realize that you only have an egg on your shelf."
			"\nYou look at your flatmate s shelf and he has a slice of bacon."
			"\n It looks so delicious and you are so hungry that you choose to steal it."
			"\n As it is sizzling in your pan, your flatmate comes into the kitchen and catches you red - handed, cooking his bacon."
			"\n While you are both arguing, your slice of bacon burns to a crispand your fire alarm goes off. "
			"\n There is no fire, but the alarm won t stop ringing.Both your phone and your flatmate s phone have no charge."
			"\n However you know that the SPIS will yell at you if they come to your flat just because you burnt a piece of bacon"
			"\n Therefore, you decide to run to the SPIS station to warn them that the fire is under control."
			"\n Here are some instructions on how to move around the campus :"
			"\n"
			"\n Press Space to jump"
			"\n Press Escape to access the menu"
			"\n Beware!The campus can be dangerous!Avoid spikes and lava* as you run by jumping over them."
			"\n Be careful though, spikes are higher than than they look"
			"\n"
			"\n * To make this game more therapeutic, one could interpret the spikes and lava as exams, deadlines, "
			"\n or any other source of anguish they would like to avoid."
			"\n"
			"\n Press C to close this tab and if you forget anything, press C again."
			"\n"
			"\n Have Fun!"));


	}
}

void CharacterTab::render(sf::RenderTarget& target)
{
	if (!this->hidden)
	{
		target.draw(back);
		target.draw(infoText);
	}
}
