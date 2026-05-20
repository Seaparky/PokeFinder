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

		void SetType(Type aPType) { type = aPType; };
		void SetType(int aPType) { type = static_cast<Type>(aPType); };

		bool operator==(const PKType& aOther) const
		{
			return operator==(aOther.type);
		}

		bool operator==(const Type& aOther) const
		{
			return type == aOther;
		}

	private:

		Type type;


	};


}