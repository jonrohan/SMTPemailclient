#pragma once
#include "mailSentDialog.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//using namespace System::Runtime::InteropServices;

extern "C++"
{
	bool connectToSmtp();
	void setSmtpMessage(String*,String*,String*);
	bool sendSmtpMessage(String* []);
	void quit();

}
namespace SMTPemailclient
{
	/// <summary> 
	/// Summary for newMessageForm
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public __gc class newMessageForm : public System::Windows::Forms::Form
	{
	public: 
		newMessageForm(void)
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
	private: System::Windows::Forms::MainMenu *  mainMenu1;
	private: System::Windows::Forms::MenuItem *  menuItem1;
	private: System::Windows::Forms::Panel *  panel1;
	private: System::Windows::Forms::Panel *  panel2;

	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Label *  label2;
	private: System::Windows::Forms::Label *  label3;



	private: System::Windows::Forms::MenuItem *  cancelMenuItem;
	private: System::Windows::Forms::TextBox *  subjectTextBox;
	private: System::Windows::Forms::TextBox *  fromTextBox;
	private: System::Windows::Forms::TextBox *  toTextBox;
	private: System::Windows::Forms::RichTextBox *  messageTextBox;
	private: String* emailAddresses[];
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
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(SMTPemailclient::newMessageForm));
			this->mainMenu1 = new System::Windows::Forms::MainMenu();
			this->menuItem1 = new System::Windows::Forms::MenuItem();
			this->cancelMenuItem = new System::Windows::Forms::MenuItem();
			this->panel1 = new System::Windows::Forms::Panel();
			this->subjectTextBox = new System::Windows::Forms::TextBox();
			this->fromTextBox = new System::Windows::Forms::TextBox();
			this->toTextBox = new System::Windows::Forms::TextBox();
			this->label3 = new System::Windows::Forms::Label();
			this->label2 = new System::Windows::Forms::Label();
			this->label1 = new System::Windows::Forms::Label();
			this->panel2 = new System::Windows::Forms::Panel();
			this->messageTextBox = new System::Windows::Forms::RichTextBox();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainMenu1
			// 
			System::Windows::Forms::MenuItem* __mcTemp__1[] = new System::Windows::Forms::MenuItem*[2];
			__mcTemp__1[0] = this->menuItem1;
			__mcTemp__1[1] = this->cancelMenuItem;
			this->mainMenu1->MenuItems->AddRange(__mcTemp__1);
			// 
			// menuItem1
			// 
			this->menuItem1->Index = 0;
			this->menuItem1->Text = S"Send";
			this->menuItem1->Click += new System::EventHandler(this, menuItem1_Click);
			// 
			// cancelMenuItem
			// 
			this->cancelMenuItem->Index = 1;
			this->cancelMenuItem->Text = S"Cancel";
			this->cancelMenuItem->Click += new System::EventHandler(this, cancelMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->subjectTextBox);
			this->panel1->Controls->Add(this->fromTextBox);
			this->panel1->Controls->Add(this->toTextBox);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = S"panel1";
			this->panel1->Size = System::Drawing::Size(488, 112);
			this->panel1->TabIndex = 0;
			// 
			// subjectTextBox
			// 
			this->subjectTextBox->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->subjectTextBox->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->subjectTextBox->Location = System::Drawing::Point(104, 80);
			this->subjectTextBox->Name = S"subjectTextBox";
			this->subjectTextBox->Size = System::Drawing::Size(376, 22);
			this->subjectTextBox->TabIndex = 5;
			this->subjectTextBox->Text = S"";
			// 
			// fromTextBox
			// 
			this->fromTextBox->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->fromTextBox->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->fromTextBox->Location = System::Drawing::Point(104, 48);
			this->fromTextBox->Name = S"fromTextBox";
			this->fromTextBox->Size = System::Drawing::Size(376, 22);
			this->fromTextBox->TabIndex = 4;
			this->fromTextBox->Text = S"";
			// 
			// toTextBox
			// 
			this->toTextBox->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right);
			this->toTextBox->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->toTextBox->Location = System::Drawing::Point(104, 16);
			this->toTextBox->Name = S"toTextBox";
			this->toTextBox->Size = System::Drawing::Size(376, 22);
			this->toTextBox->TabIndex = 3;
			this->toTextBox->Text = S"";
			// 
			// label3
			// 
			this->label3->Font = new System::Drawing::Font(S"Lucida Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label3->Location = System::Drawing::Point(8, 48);
			this->label3->Name = S"label3";
			this->label3->Size = System::Drawing::Size(88, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = S"From:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Font = new System::Drawing::Font(S"Lucida Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label2->Location = System::Drawing::Point(8, 80);
			this->label2->Name = S"label2";
			this->label2->Size = System::Drawing::Size(88, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = S"Subject:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->Font = new System::Drawing::Font(S"Lucida Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label1->Location = System::Drawing::Point(8, 16);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(88, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = S"To:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->messageTextBox);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->DockPadding->All = 3;
			this->panel2->Location = System::Drawing::Point(0, 112);
			this->panel2->Name = S"panel2";
			this->panel2->Size = System::Drawing::Size(488, 297);
			this->panel2->TabIndex = 1;
			// 
			// messageTextBox
			// 
			this->messageTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messageTextBox->Location = System::Drawing::Point(3, 3);
			this->messageTextBox->Name = S"messageTextBox";
			this->messageTextBox->Size = System::Drawing::Size(482, 291);
			this->messageTextBox->TabIndex = 0;
			this->messageTextBox->Text = S"";
			// 
			// newMessageForm
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(488, 409);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->Menu = this->mainMenu1;
			this->Name = S"newMessageForm";
			this->Text = S"New email";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}		

	private: System::Void menuItem1_Click(System::Object *  sender, System::EventArgs *  e)
			 {
				bool valid;
				mailSentDialog * d = new mailSentDialog();
				d->ShowDialog();
				if(d->getResult())
				{
					d->Close();
					setupMessage();
					valid = connectToSmtp();
					if(!valid)
					{
						mailSentDialog * dia = new mailSentDialog();
						dia->label1->set_Text("Connection Failure!");
						dia->ShowDialog();
						if(dia->getResult())
							dia->Close();
						
					}		
					valid = sendSmtpMessage(this->emailAddresses);
					if(!valid)
					{
						mailSentDialog * dia = new mailSentDialog();
						dia->label1->set_Text("Error sending mail!");
						dia->ShowDialog();
						if(dia->getResult())
							dia->Close();
						
					}
					//quit();
				}
				this->clearTextBoxes();
	
			 }

	void setupMessage()
	{
		String* toString = S"";
		String* fromString = S"";
		String* subjectString = S"";
		String* messageString = S"";
		toString = this->toTextBox->get_Text();	
		fromString = this->fromTextBox->get_Text();
		subjectString = this->subjectTextBox->get_Text();
		messageString = this->messageTextBox->get_Text();
		this->parseSeperateEmails(toString);
		setSmtpMessage(fromString,subjectString,messageString);
	}

	void parseSeperateEmails(String* toString)
	{
		String* delimStr = S";,";
		Char delimiter[] = delimStr->ToCharArray();
		String* split[] = 0;
		
		for (int x = 1; x <= 25; x++) 
		{
			split = toString->Split(delimiter, x);
		}
		this->emailAddresses = split;
		
	}

	void clearTextBoxes()
	{
		this->toTextBox->Text = "";
		this->fromTextBox->Text = "";
		this->subjectTextBox->Text = "";
		this->messageTextBox->Text = "";
	}



private: System::Void cancelMenuItem_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 this->Close();
		 }

};
}