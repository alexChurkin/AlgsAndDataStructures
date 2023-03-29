#pragma once
#include "Convertex.h"

int AddRow(
	System::Windows::Forms::DataGridView^ dgv,
	System::Drawing::Color textColor,
	...cli::array<System::String^>^ row)
{
	dgv->Rows->Add(row);
	int newRowIndex = dgv->RowCount - 1;

	dgv->Rows[newRowIndex]->DefaultCellStyle->ForeColor = textColor;
	dgv->Rows[newRowIndex]->DefaultCellStyle->SelectionForeColor = textColor;
	return newRowIndex;
}

int AddRowWithScroll(
	System::Windows::Forms::DataGridView^ dgv,
	System::Drawing::Color textColor,
	...cli::array<System::String^>^ row)
{
	int newRowIndex = AddRow(dgv, textColor, row);
	dgv->FirstDisplayedScrollingRowIndex = newRowIndex;
	return newRowIndex;
}

//Adds a new row with custom textColor
int AddRow(
	System::Windows::Forms::DataGridView^ dgv,
	System::Drawing::Color textColor,
	std::string row)
{
	return AddRow(dgv, textColor, Convertex::stringTo_String(row));
}

//Adds a new row with custom textColor and scrolls to it
int AddRowWithScroll(
	System::Windows::Forms::DataGridView^ dgv,
	System::Drawing::Color textColor,
	std::string row)
{
	return AddRowWithScroll(dgv, textColor, Convertex::stringTo_String(row));
}