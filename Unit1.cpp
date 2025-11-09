//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
char currentPlayerSymbol='X';


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	currentPlayerSymbolLabel->Text= currentPlayerSymbol;
	winnerLabel->Text = "";
	gameOver = false;
}
//---------------------------------------------------------------------------
bool TForm1::CheckIsWinner(){

	if(Button1->Text==Button2->Text && Button1->Text==Button3->Text)
		return true;
	if(!Button4->Text.IsEmpty() && Button4->Text==Button5->Text && Button4->Text==Button6->Text)
		return true;
	if(!Button7->Text.IsEmpty() && Button7->Text==Button8->Text && Button7->Text==Button9->Text)
		return true;
	if(!Button1->Text.IsEmpty() && Button1->Text==Button4->Text && Button1->Text==Button7->Text)
		return true;
	if(!Button2->Text.IsEmpty() && Button2->Text==Button5->Text && Button2->Text==Button8->Text)
		return true;
	if(!Button3->Text.IsEmpty() && Button3->Text==Button6->Text && Button3->Text==Button9->Text)
		return true;
	if(Button1->Text==Button5->Text && Button1->Text==Button9->Text)
		return true;
	if(!Button3->Text.IsEmpty() && Button3->Text==Button5->Text && Button3->Text==Button7->Text)
		return true;

	return false;
}
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
		 bool gameOver = false;
         if (gameOver)
			return;

		 TButton* clickedButton=dynamic_cast<TButton*>(Sender);
		 if (!clickedButton) return;

         if (clickedButton->Text != "")
			return;

		 clickedButton->Text=currentPlayerSymbol;

		 if(CheckIsWinner()){
			winnerLabel->Text = "Player " + String(currentPlayerSymbol)
			+ " has won!!!";
			gameOver = true;
			return  ;
		 }
         if (Button1->Text != "" && Button2->Text != "" && Button3->Text != "" &&
			 Button4->Text != "" && Button5->Text != "" && Button6->Text != "" &&
			 Button7->Text != "" && Button8->Text != "" && Button9->Text != "")
		 {
			 winnerLabel->Text = "It's a draw!";
			 gameOver = true;
			 return;
		 }

		 if(currentPlayerSymbol=='X')
			currentPlayerSymbol='O';
		 else
			currentPlayerSymbol='X';

		 currentPlayerSymbolLabel->Text= currentPlayerSymbol;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::resetClick(TObject *Sender)
{
     Button1->Text = "";
	 Button2->Text = "";
	 Button3->Text = "";
	 Button4->Text = "";
	 Button5->Text = "";
	 Button6->Text = "";
	 Button7->Text = "";
	 Button8->Text = "";
	 Button9->Text = "";

    // Reset player and labels
	 currentPlayerSymbol = 'X';
	 currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	 winnerLabel->Text = "";

    // Allow clicking again
	gameOver = false;
}
//---------------------------------------------------------------------------
