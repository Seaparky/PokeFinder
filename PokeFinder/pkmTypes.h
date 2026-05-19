#pragma once


namespace Sparky
{

	enum class Type
	{
		Bird,
		Normal,
		Fire,
		Water,
		Electric,
		Grass,
		Ice,
		Fighting,
		Poison,
		Ground,
		Flying,
		Psychic,
		Bug,
		Rock,
		Ghost,
		Dragon,
		Dark,
		Steel,
		Fairy
	};


	class PKType
	{
	public:

		void SetPrimary(Type aPType) { Primary = aPType; };
		void SetPrimary(int aPType) { Primary = static_cast<Type>(aPType); };
		void SetSecondary(Type aSType) { Secondary = aSType; };
		void SetSecondary(int aSType) { Secondary = static_cast<Type>(aSType); };


	private:

		Type Primary;
		Type Secondary;

	};


}