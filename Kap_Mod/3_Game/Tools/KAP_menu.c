// Script File

class KAP_menu extends UIScriptedMenu{

    static const int MENU_ID = 11260602027;
    static string TARGET_ICON = "\\DZ\\gear\\navigation\\data\\map_viewpoint_ca.paa";

    private Widget          m_Root;
    private TextWidget     m_Message;
    private TextListboxWidget m_TargetList;
    private RichTextWidget m_html;

    static KAP_menu instance;

    void KAP_menu()
	{
		
		if ( !instance )
		{
			instance = this;
		}
	}

    override Widget Init(){
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "KapMod/kap_mod/layout/kapmod.layout" );

        m_Message =  TextWidget.Cast(layoutRoot.FindAnyWidget( "KapWidgetText" ));
        m_TargetList = TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "KapWidgetTextListBox" ) );
        m_html = RichTextWidget.Cast( layoutRoot.FindAnyWidget( "KapWidgetRichText" ) );

        return layoutRoot;
    }

    TextListboxWidget GetList(){
        return m_TargetList;
    }

    void SetMessage(string msg){
        m_Message.SetText(msg);
    }
	void SetLineText(array<string> text){
		string s;
		for(int i = 0; i < text.Count(); i++){
			s += text[i] + " ";
		}
		m_html.SetText(s);
	}
	override void OnShow(){
        super.OnShow();

		PPEffects.SetBlurMenu(1);
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetMission().GetHud().Show( false );
	}
	
	override void OnHide(){
        super.OnHide();

		PPEffects.SetBlurMenu(0);

		GetGame().GetInput().ResetGameFocus();
		GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetMission().GetHud().Show( true );
	}

    void Show(){
		if (layoutRoot)
			layoutRoot.Show(true);
	}
	
	void Hide(){
		if (layoutRoot)
			layoutRoot.Show(false);
	}
}