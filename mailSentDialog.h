#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SMTPemailclient
{
	/// <summary> 
	/// Summary for mailSentDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public __gc class mailSentDialog : public System::Windows::Forms::Form
	{
	public: 
		mailSentDialog(void)
		{
			InitializeComponent();
			this->clicked = false;
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
	public: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Button *  button1;
	public: bool clicked;
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
			this->label1 = new System::Windows::Forms::Label();
			this->button1 = new System::Windows::Forms::Button();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(8, 8);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(200, 64);
			this->label1->TabIndex = 0;
			this->label1->Text = S"Email sent to the recipient address provided.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(56, 80);
			this->button1->Name = S"button1";
			this->button1->Size = System::Drawing::Size(112, 24);
			this->button1->TabIndex = 1;
			this->button1->Text = S"OK";
			this->button1->Click += new System::EventHandler(this, button1_Click);
			// 
			// mailSentDialog
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(7, 16);
			this->ClientSize = System::Drawing::Size(218, 120);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = new System::Drawing::Font(S"Century Schoolbook", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = S"mailSentDialog";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = S" ";
			this->ResumeLayout(false);

		}		
	private: System::Void button1_Click(System::Object *  sender, System::EventArgs *  e)
			 {
				 this->clicked = true;
				 this->SendToBack();
				 this->Visible = false;
			 }

	public:bool getResult()
	 {
		 return clicked;
	 }
	};
}