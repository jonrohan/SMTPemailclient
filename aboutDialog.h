#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SMTPemailclient
{
	///<summary>
	///AUTHOR: Jon Rohan
	///TITLE: SMTP/POP3 email client
	///DATE: 3.29.2005
	///PURPOSE: The purpose of this class is to display an about Dialog to the user
	///</summary>
	public __gc class aboutDialog : public System::Windows::Forms::Form
	{
	public: 
		aboutDialog(void)
		{
			InitializeComponent();
		}
        
	protected: 
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::Label *  title;
	private: System::Windows::Forms::PictureBox *  mailboxImage;
	private: System::Windows::Forms::Label *  infoLine1;
	private: System::Windows::Forms::Label *  infoLine2;
	private: System::Windows::Forms::Label *  infoLine3;
	private: System::Windows::Forms::Button *  okButton;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container* components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(SMTPemailclient::aboutDialog));
			this->title = new System::Windows::Forms::Label();
			this->mailboxImage = new System::Windows::Forms::PictureBox();
			this->infoLine1 = new System::Windows::Forms::Label();
			this->infoLine2 = new System::Windows::Forms::Label();
			this->infoLine3 = new System::Windows::Forms::Label();
			this->okButton = new System::Windows::Forms::Button();
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->BackColor = System::Drawing::Color::SteelBlue;
			this->title->Dock = System::Windows::Forms::DockStyle::Top;
			this->title->Font = new System::Drawing::Font(S"Lucida Sans", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->title->Location = System::Drawing::Point(0, 0);
			this->title->Name = S"title";
			this->title->Size = System::Drawing::Size(480, 72);
			this->title->TabIndex = 0;
			this->title->Text = S"Simple SMTP/POP3 Mail Client";
			this->title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mailboxImage
			// 
			this->mailboxImage->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"mailboxImage.Image")));
			this->mailboxImage->Location = System::Drawing::Point(8, 64);
			this->mailboxImage->Name = S"mailboxImage";
			this->mailboxImage->Size = System::Drawing::Size(168, 168);
			this->mailboxImage->TabIndex = 1;
			this->mailboxImage->TabStop = false;
			// 
			// infoLine1
			// 
			this->infoLine1->Font = new System::Drawing::Font(S"Lucida Sans", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->infoLine1->Location = System::Drawing::Point(184, 112);
			this->infoLine1->Name = S"infoLine1";
			this->infoLine1->Size = System::Drawing::Size(256, 24);
			this->infoLine1->TabIndex = 2;
			this->infoLine1->Text = S"Created by Rohansoft Inc.";
			// 
			// infoLine2
			// 
			this->infoLine2->Font = new System::Drawing::Font(S"Lucida Sans", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->infoLine2->Location = System::Drawing::Point(184, 136);
			this->infoLine2->Name = S"infoLine2";
			this->infoLine2->Size = System::Drawing::Size(280, 24);
			this->infoLine2->TabIndex = 3;
			this->infoLine2->Text = S"Copyright 2005 All Rights Reserved";
			// 
			// infoLine3
			// 
			this->infoLine3->Font = new System::Drawing::Font(S"Lucida Sans", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->infoLine3->Location = System::Drawing::Point(184, 160);
			this->infoLine3->Name = S"infoLine3";
			this->infoLine3->Size = System::Drawing::Size(256, 24);
			this->infoLine3->TabIndex = 4;
			this->infoLine3->Text = S"Jon Rohan";
			// 
			// okButton
			// 
			this->okButton->Font = new System::Drawing::Font(S"Lucida Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->okButton->Location = System::Drawing::Point(360, 232);
			this->okButton->Name = S"okButton";
			this->okButton->Size = System::Drawing::Size(80, 32);
			this->okButton->TabIndex = 5;
			this->okButton->Text = S"OK";
			this->okButton->Click += new System::EventHandler(this, button1_Click);
			// 
			// aboutDialog
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(480, 286);
			this->ControlBox = false;
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->infoLine3);
			this->Controls->Add(this->infoLine2);
			this->Controls->Add(this->infoLine1);
			this->Controls->Add(this->title);
			this->Controls->Add(this->mailboxImage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = S"aboutDialog";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = S" ";
			this->TopMost = true;
			this->ResumeLayout(false);

		}		

	private: System::Void button1_Click(System::Object *  sender, System::EventArgs *  e)
			 {
				 this->Close();
			 }

};
}