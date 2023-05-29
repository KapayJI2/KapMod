// Script File
class KapMegaphone: Megaphone{
	/*
    PlayerBase m_itemowner;
    override void OnSwitchOn(){
        super.OnSwitchOn();
        //тут получаем список игроков в массив, проходим по всем игрокам и вызываем у них метод форсированной блевоты
        //с проверкой на включившего мегафон, у него вызываем кашель, хз зачем, просто так, почему бы и нет
        array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);
        float max_distance = 100.0;
        for(int i = 0; i < players.Count(); i++)
        {    
            PlayerBase player = PlayerBase.Cast(players.Get(i));
            Print("CHK: " + player);
            Print("CHK2: " + m_itemowner);
            if(player != m_itemowner && (vector.Distance(m_itemowner.GetPosition(), player.GetPosition()) < max_distance)){
                GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( TryPlayerCallVomit, 10000, true, player);
                //player.OnPlayerVomitForce();
            }
			if(player == m_itemowner){
                GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( TryPlayerCallCough, 10000, true, player);
                //player.OnPlayerCoughForce();
            };
        }
        //m_itemowner.OnItemOn();
    };
	override void OnSwitchOff(){
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(TryPlayerCallVomit);
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(TryPlayerCallCough);
		super.OnSwitchOff();
	};
    override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner){
        super.OnItemLocationChanged(old_owner, new_owner);
		m_itemowner = PlayerBase.Cast(new_owner);
        Print(PlayerBase.Cast(new_owner) == m_itemowner.GetInstance());
        //проверяем является ли игрок владельцем мегафона и в руках ли предмет
        //если да - принудительно устанавливаем владельца
        //p.s. При работе с массивом игроков, впринципе, не актуально, но можно что-то намутить
        if(PlayerBase.Cast(new_owner) == m_itemowner.GetInstance()){
            this.SetItemOwner(PlayerBase.Cast(new_owner));
        }else{
            //если итем был перемещён в рюкзак или на землю - удаляем инфу о владельце
            this.RemoveItemOwner();
        };
		Print(PlayerBase.Cast(new_owner) == m_itemowner.GetInstance());
		Print("CHK3: " + PlayerBase.Cast(new_owner));
        Print("CHK4: " + m_itemowner.GetInstance());
    };
    //принудительно устанавливаем владельца
    void SetItemOwner(PlayerBase player){
        m_itemowner = player;
    };
    //удаляем владельца
    void RemoveItemOwner(){
        m_itemowner = null;
    };
    void TryPlayerCallVomit(PlayerBase cur_player){
        GetGame().GameScript.CallFunction(cur_player, "OnPlayerVomitForce", cur_player, 0);
        //player.OnPlayerVomitForce();
    };
    void TryPlayerCallCough(PlayerBase cur_player){
        GetGame().GameScript.CallFunction(cur_player, "OnPlayerCoughForce", cur_player, 0);
        //player.OnPlayerCoughForce();
    };
	*/
};