#using <System.Data.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Data;

/// <summary>
/// Summary description for Form1.
/// </summary>
public ref class Form1: public System::Windows::Forms::Form
{
private:
   System::Windows::Forms::RichTextBox^ richTextBox1;
   System::Windows::Forms::Button^ button1;

   /// <summary>
   /// Required designer variable.
   /// </summary>
   System::ComponentModel::Container^ components;

public:
   Form1()
   {
      //
      // Required for Windows Form Designer support
      //
      InitializeComponent();

      //
      // TODO: Add any constructor code after InitializeComponent call
      //
   }

public:

   /// <summary>
   /// Clean up any resources being used.
   /// </summary>
   ~Form1()
   {
      if ( components != nullptr )
      {
         delete components;
      }
   }

private:

   /// <summary>
   /// Required method for Designer support - do not modify
   /// the contents of this method with the code editor.
   /// </summary>
   void InitializeComponent()
   {
      this->richTextBox1 = gcnew System::Windows::Forms::RichTextBox;
      this->button1 = gcnew System::Windows::Forms::Button;
      this->SuspendLayout();

      // 
      // richTextBox1
      // 
      this->richTextBox1->Location = System::Drawing::Point( 32, 40 );
      this->richTextBox1->Name = "richTextBox1";
      this->richTextBox1->Size = System::Drawing::Size( 240, 208 );
      this->richTextBox1->TabIndex = 0;
      this->richTextBox1->Text = "richTextBox1";

      // 
      // button1
      // 
      this->button1->Location = System::Drawing::Point( 328, 64 );
      this->button1->Name = "button1";
      this->button1->TabIndex = 1;
      this->button1->Text = "button1";
      this->button1->Click += gcnew System::EventHandler( this, &Form1::button1_Click );

      // 
      // Form1
      // 
      this->ClientSize = System::Drawing::Size( 432, 350 );
      array<System::Windows::Forms::Control^>^temp0 = {this->button1,this->richTextBox1};
      this->Controls->AddRange( temp0 );
      this->Name = "Form1";
      this->Text = "Form1";
      this->ResumeLayout( false );
   }

   void button1_Click( Object^ /*sender*/, System::EventArgs^ /*e*/ )
   {
      // Selects all text in the control.
      richTextBox1->SelectAll();
      richTextBox1->Cut();
      richTextBox1->Undo();
      RedoAllButDeletes();
   }

   //<Snippet1>
private:
   void RedoAllButDeletes()
   {
      // Determines if a Redo operation can be performed.
      if ( richTextBox1->CanRedo )
      {
         // Determines if the redo operation deletes text.
         if (  !richTextBox1->RedoActionName->Equals( "Delete" ) )
         // Perform the redo.
         richTextBox1->Redo();
      }
   }
   //</Snippet1>
};

/// <summary>
/// The main entry point for the application.
/// </summary>

[STAThread]
int main()
{
   Application::Run( gcnew Form1 );
}
