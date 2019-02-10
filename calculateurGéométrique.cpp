#include <iostream>
#include <string>
#include <cmath>
#include <limits>

#include "namespaces.hpp"

template <typename T>
bool verifyInput(T& n, const std::string& promptMessage = "")
{
	std::cout << promptMessage << std::endl;

	while (!(std::cin >> n))
	{
		if (std::cin.eof())
		{
			return false;
		}
		else if (std::cin.fail())
		{
			std::cout << "Entree incorrecte, recommencez" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return true;
}

int main()
{
	std::cout << "Bienvenue dans le calculateur geometrique de perimetre / d'aire / de volume cree par Romain Bricout." << std::endl << std::endl;
	std::cout << "Vous pouvez calculer les aires des figures suivantes : rectangle / carre / disque / parallelogramme / triangle / trapeze / losange / sphere / cone / cube / pave droit / cylindre / pyramide a base carree" << std::endl << std::endl;
	std::cout << "Vous pouvez aussi calculer les perimetres des figures suivantes : rectangle / carre / cercle / parallelogramme / triangle / trapeze et losange" << std::endl << std::endl;
	std::cout << "Vous pouvez egalement calculer les volumes des figures suivantes : cube / pave droit / cylindre / cone / pyramide a base carree / pyramide a base rectangle et sphere." << std::endl << std::endl;
	std::cout << "Vous pouvez utiliser le theoreme de Pythagore ou le theoreme de Thales" << std::endl << std::endl;
	std::cout << "Il est important d'ecrire le nom des figures comme ci-dessus !" << std::endl;
	std::cout << "Execptions : 'pyramide a base carree' devient 'pyramide_c' / 'pyramide a base rectangle' devient 'pyramide_r'" << std::endl << "et 'pave droit' devient 'p_d'" << std::endl;
	std::cout << "Veillez aussi a rentrer toutes les mesures en cm !" << std::endl << std::endl;

	std::string restart{ "oui" };
	while (restart == "oui")
	{
		std::string choice;
		if (verifyInput(choice, "De quelle figure voulez vous calculer l'aire / le perimetre / le volume ? Ecrivez 'pythagore' pour effectuer un theoreme de Pythagore et 'thales' pour effectuer un theoreme de Thales"))
		{
			if (choice == "rectangle")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le perimetre d'un rectangle ?"))
				{
					if (calculationChoice == "aire")
					{
						double length{ 0 };
						double width{ 0 };

						if (verifyInput(length, "Entrez la dimension des longueurs") && verifyInput(width, "Entrez la dimension des largeurs"))
						{
							double result{ area::rectangle(length, width) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << length << " * " << width << std::endl;
						}
					}
					else if (calculationChoice == "perimetre")
					{
						double length{ 0 };
						double width{ 0 };

						if (verifyInput(length, "Entrez la dimension des longueurs") && verifyInput(width, "Entrez la dimension des largeurs"))
						{
							double result{ perimeter::rectangle(length, width) };
							std::cout << "P = " << result << " cm" << std::endl;
							std::cout << "Calcul : " << length << " * 2 + " << width << " * 2" << std::endl;
						}
					}
				}
			}

			else if (choice == "carre")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le perimetre d'un carre ?"))
				{
					if (calculationChoice == "aire")
					{
						double side{ 0 };

						if (verifyInput(side, "Entrez la dimension des cotes"))
						{
							double result{ area::square(side) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << side << "^2" << std::endl;
						}
					}
					else if (calculationChoice == "perimetre")
					{
						double side{ 0 };

						if (verifyInput(side, "Entrez la longueur des cotes"))
						{
							double result{ perimeter::square(side) };
							std::cout << "P = " << result << " cm" << std::endl;
							std::cout << "Calcul : " << side << " * 4" << std::endl;
						}
					}
				}
			}

			else if (choice == "triangle")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le perimetre d'un triangle ?"))
				{
					if (calculationChoice == "aire")
					{
						double base{ 0 };
						double height{ 0 };

						if (verifyInput(base, "Entrez la dimension de la base") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ area::triangle(base, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << "(" << base << " * " << height << ") / 3" << std::endl;
						}
					}
					else if (calculationChoice == "perimetre")
					{
						double base{ 0 };
						double firstSide{ 0 };
						double secondSide{ 0 };

						if (verifyInput(base, "Entrez la dimension de la base") && verifyInput(firstSide, "Entrez la dimension du premier cote") && verifyInput(secondSide, "Entrez la dimension du second cote"))
						{
							double result{ perimeter::triangle(base, firstSide, secondSide) };
							std::cout << "P = " << result << " cm" << std::endl;
							std::cout << "Calcul : " << base << " + " << firstSide << " + " << secondSide << std::endl;
						}
					}
				}
			}

			else if (choice == "disque")
			{
				double radius{};
				if (verifyInput(radius, "Entrez la dimension du rayon"))
				{
					double result{ area::disk(radius) };
					std::cout << "A = " << result << " cm^2" << std::endl;
					std::cout << "Calcul : " << radius << "cm^2 * pi" << std::endl;
				}
			}

			else if (choice == "parallelogramme")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le perimetre d'un parallelogramme ?"))
				{
					if (calculationChoice == "aire")
					{
						double base{ 0 };
						double height{ 0 };

						if (verifyInput(base, "Entrez la dimension de la base") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ area::parallelogram(base, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << base << " * " << height << std::endl;
						}
					}

					else if (calculationChoice == "perimetre")
					{
						double length{ 0 };
						double width{ 0 };

						if (verifyInput(length, "Entrez la dimension de la longueur") && verifyInput(width, "Entrez la dimension de la largeur"))
						{
							double result{ perimeter::parallelogram(length, width) };
							std::cout << "P = " << result << " cm" << std::endl;
							std::cout << "Calcul : " << length << " * 2 + " << width << " * 2" << std::endl;
						}
					}
				}
			}

			else if (choice == "trapeze")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le perimetre d'un trapeze ?"))
				{
					if (calculationChoice == "aire")
					{
						double firstBase{ 0 };
						double secondBase{ 0 };
						double height{ 0 };

						if (verifyInput(firstBase, "Entrez la dimension de la premiere base") && verifyInput(secondBase, "Entrez la dimension de la seconde base") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ area::trapeze(firstBase, secondBase, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << "((" << firstBase << " + " << secondBase << ") * " << height << ") / 2" << std::endl;
						}
					}
					else if (calculationChoice == "perimetre")
					{
						double firstBase{ 0 };
						double secondBase{ 0 };
						double firstSide{ 0 };
						double secondSide{ 0 };

						if (verifyInput(firstBase, "Entrez la dimension de la premiere base") && verifyInput(secondBase, "Entrez la dimension de la seconde base") && verifyInput(firstSide, "Entrez la dimension du premier cote") && verifyInput(secondSide, "Entrez la dimension du second cote"))
						{
							double result{ perimeter::trapeze(firstBase, secondBase, firstSide, secondSide) };
							std::cout << "P = " << result << " cm" << std::endl;
							std::cout << "Calcul : " << firstBase << " + " << firstSide << " + " << secondBase << " + " << secondSide << std::endl;
						}
					}
				}
			}

			else if (choice == "losange")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le perimetre d'un losange ?"))
				{
					if (calculationChoice == "aire")
					{
						double firstDiagonal{ 0 };
						double secondDiagonal{ 0 };

						if (verifyInput(firstDiagonal, "Entrez la dimension de la premiere diagonale") && verifyInput(secondDiagonal, "Entrez la dimension de la seconde diagonale"))
						{
							double result{ area::diamond(firstDiagonal, secondDiagonal) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << firstDiagonal << " * " << secondDiagonal << " / 2" << std::endl;
						}
					}

					else if (calculationChoice == "perimetre")
					{
						double side{ 0 };

						if (verifyInput(side, "Entrez la dimension d'un des cotes"))
						{
							double result{ perimeter::diamond(side) };
							std::cout << "P = " << result << " cm" << std::endl;
							std::cout << "Calcul : " << side << " * 4" << std::endl;
						}
					}
				}
			}

			else if (choice == "sphere")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le volume d'une sphere ?"))
				{
					if (calculationChoice == "aire")
					{
						double radius{ 0 };

						if (verifyInput(radius, "Entrez la dimension du rayon"))
						{
							double result{ area::sphere(radius) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << radius << "^2 * (pi * 4)" << std::endl;
						}
					}

					else if (calculationChoice == "volume")
					{
						double radius{ 0 };

						if (verifyInput(radius, "Entrez la dimension du rayon"))
						{
							double result{ volume::sphere(radius) };
							std::cout << "V = " << result << " cm^3" << std::endl;
							std::cout << "Calcul : (4 / 3) * pi * " << radius << "^3" << std::endl;
						}
					}
				}
			}

			else if (choice == "cone")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous caculer l'aire ou le volume d'un cone ?"))
				{
					if (calculationChoice == "aire")
					{
						double radius{ 0 };
						double height{ 0 };

						if (verifyInput(radius, "Entrez la dimension du rayon") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ area::cone(radius, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : racine carree de (" << radius << "^2 + " << height << "^2 * pi * " << radius << std::endl;
						}
					}

					else if (calculationChoice == "volume")
					{
						double radius{ 0 };
						double height{ 0 };

						if (verifyInput(radius, "Entrez la dimension du rayon") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ volume::cone(radius, height) };
							std::cout << "V = " << result << " cm^3" << std::endl;
							std::cout << "Calcul : (pi * " << radius << "^2 * " << height << ") / 3" << std::endl;
						}
					}
				}
			}

			else if (choice == "cube")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le volume d'un cube ?"))
				{
					if (calculationChoice == "aire")
					{
						double arete{};
						if (verifyInput(arete, "Entrez la dimension d'une arrete"))
						{
							double result{ area::cube(arete) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : " << arete << "^2 * 6" << std::endl;
						}
					}

					else if (calculationChoice == "volume")
					{
						double arete{};
						if (verifyInput(arete, "Entrez la dimension d'une arete"))
						{
							double result{ volume::cube(arete) };
							std::cout << "V = " << result << " cm^3" << std::endl;
							std::cout << "Calcul : " << arete << "^3" << std::endl;
						}
					}
				}
			}

			else if (choice == "p_d")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le volume d'un pave droit ?"))
				{
					if (calculationChoice == "aire")
					{
						double length{};
						double width{};
						double height{};

						if (verifyInput(length, "Entrez la dimension des longueurs") && verifyInput(width, "Entrez la dimension des largeurs") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ area::rectangleCuboid(length, width, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : (2 * " << length << " * " << width << ") + (2 * " << length << " * " << height << ") + (2 * " << width << " * " << height << ")" << std::endl;
						}
					}

					else if (calculationChoice == "volume")
					{
						double length{};
						double width{};
						double height{};

						if (verifyInput(length, "Entrez la dimension des longueurs") && verifyInput(width, "Entrez la dimension des largeurs") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ volume::rectangleCuboid(length, width, height) };
							std::cout << "V = " << result << " cm^3" << std::endl;
							std::cout << "Calcul : " << length << " * " << width << " * " << height << std::endl;
						}
					}
				}
			}

			else if (choice == "cylindre")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le volume d'un cylindre ?"))
				{
					if (calculationChoice == "aire")
					{
						double radius{};
						double height{};

						if (verifyInput(radius, "Entrez la dimension du rayon") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ area::cylinder(radius, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : 2 * pi * " << radius << " * " << height << std::endl;
						}
					}

					else if (calculationChoice == "volume")
					{
						double radius{};
						double height{};

						if (verifyInput(radius, "Entrez la dimension du rayon") && verifyInput(height, "Entrez la dimension de la hauteur"))
						{
							double result{ volume::cylinder(radius, height) };
							std::cout << "V = " << result << " cm^3" << std::endl;
							std::cout << "Calcul : pi * " << radius << "^2 * " << height << std::endl;
						}
					}
				}
			}

			else if (choice == "pyramide_c")
			{
				std::string calculationChoice{};
				if (verifyInput(calculationChoice, "Voulez vous calculer l'aire ou le volume d'une pyramide a base carree ?")) {
					if (calculationChoice == "aire") {
						double side{ 0 };
						double height{ 0 };

						if (verifyInput(side, "Entrez la dimension d'un cote") && verifyInput(height, "Entrez la dimension de la hauteur")) {
							double result{ area::squareBasedPyramid(side, height) };
							std::cout << "A = " << result << " cm^2" << std::endl;
							std::cout << "Calcul : (" << side << " * 4) * racine carre de " << height << "^2 + (" << side << " / 2)^2 / 2" << std::endl;
						}
					}
				}

				else if (calculationChoice == "volume") {
					double side{ 0 };
					double height{ 0 };

					if (verifyInput(side, "Entrez la dimension d'un cote") && verifyInput(height, "Entrez la dimension de la hauteur")) {
						double result{ volume::squareBasedPyramid(side, height) };
						std::cout << "V = " << result << " cm^3" << std::endl;
						std::cout << "Calcul : (" << side << "^2 * " << height << ") / 3" << std::endl;
					}
				}
			}

			else if (choice == "pyramide_r")
			{
				double length{ 0 };
				double width{ 0 };
				double height{ 0 };

				if (verifyInput(length, "Entrez la dimension des longueurs de la base") && verifyInput(width, "Entrez la dimension des largeurs de la base") && verifyInput(height, "Entrez la dimension de la hauteur"))
				{
					double result{ volume::rectangleBasedPyramid(length, width, height) };
					std::cout << "V = " << result << " cm^3" << std::endl;
					std::cout << "Calcul : ((" << height << " * " << width << ") * " << height << ") / 3" << std::endl;
				}
			}

			else if (choice == "pythagore")
			{
			std::string theoremVersion{};
				if (verifyInput(theoremVersion, "Voulez vous calculer une hypoténuse ou un autre cote ?"))
				{
					if (theoremVersion == "hypotenuse")
					{
						double firstSide{ 0 };
						double secondSide{ 0 };

						if (verifyInput(firstSide, "Entrez la dimension du premier cote") && verifyInput(secondSide, "Entrez la dimension du second cote"))
						{
							double result{ std::hypot(firstSide, secondSide) };
							std::cout << "La longueur de l'hypotenuse est egale a " << result << " cm" << std::endl;
							std::cout << "Calcul : racine carre de " << firstSide << "^2 + " << secondSide << "^2" << std::endl;
						}
					}

					else if (theoremVersion == "autre")
					{
						double knownSide{ 0 };
						double hypotenuse{ 0 };

						if (verifyInput(hypotenuse, "Entrez la longueur de l'hypotenuse") && verifyInput(knownSide, "Entrez la longueur du cote connu"))
						{
							double result{ theorems::pythagoreOtherSide(hypotenuse, knownSide) };
							std::cout << "La longueur du cote inconnu est egale a " << result << " cm" << std::endl;
							std::cout << "Calcul : racine carree de " << hypotenuse << "^2 - " << knownSide << "^2" << std::endl;
						}
					}
				}
			}

			else if (choice == "thales")
			{
				std::string versionChoice{};
				if (verifyInput(versionChoice, "Voulez vous calculer un numerateur (avec denominateur connu) ou un denominateur (avec numerateur connu) ?"))
				{
					if (versionChoice == "numerateur")
					{
						double knownFractionNumerator{ 0 };
						double knownFractionDenominator{ 0 };
						double knownDenominator{ 0 };

						if (verifyInput(knownFractionNumerator, "Entrez le numerateur de la fraction dont vous connaissez aussi le denominateur") && verifyInput(knownFractionDenominator, "Entrez le denominateur de la fraction dont vous connaissez aussi le numerateur") && verifyInput(knownDenominator, "Entrez le denominateur de la fraction dont vous cherchez le numerateur"))
						{
							double result{ theorems::thalesWithUnknownNumerator(knownFractionNumerator, knownFractionDenominator, knownDenominator) };
							std::cout << "La valeur du numerateur est " << result << std::endl;
							std::cout << "Calcul : (" << knownFractionNumerator << " * " << knownDenominator << ") / " << knownFractionDenominator << std::endl;
						}
					}

					else if (versionChoice == "denominateur")
					{
						double knownFractionNumerator{ 0 };
						double knownFractionDenominator{ 0 };
						double knownNumerator{ 0 };

						if (verifyInput(knownFractionNumerator, "Entrez le numerateur de la fraction dont vous connaissez aussi le denominateur") && verifyInput(knownFractionDenominator, "Entrez le denominateur de la fraction dont vous connaissez aussi le numerateur") && verifyInput(knownNumerator, "Entrez le denominateur de la fraction dont vous cherchez le numerateur"))
						{
							double result{ theorems::thalesWithUnknownDenominator(knownFractionNumerator, knownFractionDenominator, knownNumerator) };
							std::cout << "La valeur du denominateur est " << result << std::endl;
							std::cout << "Calcul : (" << knownFractionDenominator << " * " << knownNumerator << ") / " << knownFractionNumerator << std::endl;
						}
					}
				}
			}
			
			verifyInput(restart, "Voulez vous faire un autre calcul ?");
		}
	}
}
