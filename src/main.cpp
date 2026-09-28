#define MAGIC_ENUM_RANGE_MIN 0
#define MAGIC_ENUM_RANGE_MAX 512
#include <magic_enum/magic_enum.hpp>
#include <iostream>
#include "Items.h"
#include "Parser.h"

void _print_item_counts(const Items& items)
{
	std::cout << "Item completion:" << std::endl;

	int weapon_count = 0;
	for (int i = 0; i < WeaponCount; i++)
		weapon_count += items.weapons[i];
	std::cout << "Weapons: " << weapon_count << "/" << WeaponCount << std::endl;

	int picto_count = 0;
	for (int i = 0; i < PictoCount; i++)
		picto_count += items.pictos[i];
	std::cout << "Pictos: " << picto_count << "/" << PictoCount << std::endl;

	int outfit_count = 0;
	for (int i = 0; i < OutfitCount; i++)
		outfit_count += items.outfits[i];
	std::cout << "Outfits: " << outfit_count << "/" << OutfitCount << std::endl;

	int journal_count = 0;
	for (int i = 0; i < JournalCount; i++)
		journal_count += items.journals[i];
	std::cout << "Journals: " << journal_count << "/" << JournalCount << std::endl;
}

bool _area_is_complete(const Items& items, const Area& area)
{
	for (auto i: area.weapons)
		if (items.weapons[i] == 0)
			return false;

	for (auto i: area.pictos)
		if (items.pictos[i] == 0)
			return false;

	for (auto i: area.outfits)
		if (items.outfits[i] == 0)
			return false;

	for (auto i: area.journals)
		if (items.journals[i] == 0)
			return false;

	return true;
}

void _print_areas(const Items& items)
{
	std::cout << "Area completion:" << std::endl;

	for (const auto& area: AREAS)
	  std::cout << area.name << ": " << (_area_is_complete(items, area) ? "Yes" : "No") << std::endl;
}

void _print_missing_items(const Items& items)
{
	using namespace magic_enum;

	std::cout << "Missing items:" << std::endl;

	for (const auto& area: AREAS)
	{
		std::cout << area.name << ": ";
		for (auto i: area.weapons)
			if (items.weapons[i] == 0)
				std::cout << enum_name(enum_value<Weapon>(i)) << ", ";

		for (auto i: area.pictos)
			if (items.pictos[i] == 0)
				std::cout << enum_name(enum_value<Picto>(i)) << ", ";

		for (auto i: area.outfits)
			if (items.outfits[i] == 0)
				std::cout << enum_name(enum_value<Outfit>(i)) << ", ";

		for (auto i: area.journals)
			if (items.journals[i] == 0)
				std::cout << enum_name(enum_value<Journal>(i)) << ", ";

		std::cout << std::endl;
	}
}

int main(int argc, const char** argv)
{
	if (argc != 2)
	{
		std::cout << "invalid arguments: please input save file path" << std::endl;
		return -1;
	}

	const char* path = argv[1];

	Items items{};
	parse(path, items);

	_print_item_counts(items);
	std::cout << std::endl;
	_print_areas(items);
	std::cout << std::endl;

	std::cout << "Print missing items in each area? (y/n)" << std::endl;
	char a;
	std::cin >> a;
	while (a != 'y' && a != 'n')
	{
		std::cout << "Please input y or n:" << std::endl;
		std::cin >> a;
	}
	if (a == 'y')
		_print_missing_items(items);

	return 0;
}
