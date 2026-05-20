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

		std::string GetTypeName()
		{
			switch (type)
			{
			case Sparky::Type::Bird:
				return "NULL";
			case Sparky::Type::Normal:
				return "Normal";
			case Sparky::Type::Fire:
				return "Fire";
			case Sparky::Type::Water:
				return "Water";
			case Sparky::Type::Electric:
				return "Electric";
			case Sparky::Type::Grass:
				return "Grass";
			case Sparky::Type::Ice:
				return "Ice";
			case Sparky::Type::Fighting:
				return "Fighting";
			case Sparky::Type::Poison:
				return "Poison";
			case Sparky::Type::Ground:
				return "Ground";
			case Sparky::Type::Flying:
				return "Flying";
			case Sparky::Type::Psychic:
				return "Psychic";
			case Sparky::Type::Bug:
				return "Bug";
			case Sparky::Type::Rock:
				return "Rock";
			case Sparky::Type::Ghost:
				return "Ghost";
			case Sparky::Type::Dragon:
				return "Dragon";
			case Sparky::Type::Dark:
				return "Dark";
			case Sparky::Type::Steel:
				return "Steel";
			case Sparky::Type::Fairy:
				return "Fairy";
			}
		}
		Type* GetType() { return &type; }

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

